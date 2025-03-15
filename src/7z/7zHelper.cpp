#include <locale>
#include <codecvt>

#include "../log.h"

#include "7zHelper.h"

#include "Precomp.h"
#include "7z.h"
#include "7zAlloc.h"
#include "7zBuf.h"
#include "7zCrc.h"
#include "7zFile.h"
#include "7zVersion.h"

#define kInputBufSize ((size_t)1 << 18)

static ISzAlloc g_Alloc = {
    SzAlloc,
    SzFree
};


#ifdef _WIN32
  #ifndef USE_WINDOWS_FILE
    static UINT g_FileCodePage = CP_ACP;
  #endif
  #define MY_FILE_CODE_PAGE_PARAM ,g_FileCodePage
#else
  #define MY_FILE_CODE_PAGE_PARAM
#endif

std::string utf16_to_utf8(std::u16string const& s)
{
    std::wstring_convert<std::codecvt_utf8_utf16<char16_t, 0x10ffff,
        std::codecvt_mode::little_endian>, char16_t> cnv;
    std::string utf8 = cnv.to_bytes(s);
    if(cnv.converted() < s.size())
        throw std::runtime_error("incomplete conversion");
    return utf8;
}


std::list<std::string> List7zFile(const std::string &filename)
{
    std::list<std::string> contents;

    CFileInStream archiveStream;
    CLookToRead2 lookStream;
    CSzArEx db;
    SRes res;
    ISzAlloc allocImp;
    ISzAlloc allocTempImp;
    uint16_t *temp = nullptr;
    size_t tempSize = 0;

    allocImp.Alloc = SzAlloc;
    allocImp.Free = SzFree;

    allocTempImp.Alloc = SzAllocTemp;
    allocTempImp.Free = SzFreeTemp;

    {
        WRes wres =
#ifdef UNDER_CE
        InFile_OpenW(&archiveStream.file, filename.c_str()); // change it
#else
        InFile_Open(&archiveStream.file, filename.c_str());
#endif
        if (wres != 0)
        {
            Log("cannot open input file", wres);
            return contents;
        }
    }

    FileInStream_CreateVTable(&archiveStream);
    archiveStream.wres = 0;
    LookToRead2_CreateVTable(&lookStream, False);
    lookStream.buf = NULL;

    res = SZ_OK;

    {
        lookStream.buf = (Byte *)ISzAlloc_Alloc(&allocImp, kInputBufSize);
        if (!lookStream.buf)
        {
            res = SZ_ERROR_MEM;
            Log("Cannot allocate memory");
        }
        else
        {
            lookStream.bufSize = kInputBufSize;
            lookStream.realStream = &archiveStream.vt;
            LookToRead2_INIT(&lookStream)
        }
    }

    CrcGenerateTable();

    SzArEx_Init(&db);

    if (res == SZ_OK)
    {
        res = SzArEx_Open(&db, &lookStream.vt, &allocImp, &allocTempImp);
    }

    Log("Here %d", res);
//    return contents;

    if (res == SZ_OK)
    {
        uint32_t i;
        size_t listIt = 0;

        for (i = 0; i < db.NumFiles; i++)
        {
            size_t len;
            int isDir = SzArEx_IsDir(&db, i);
            len = SzArEx_GetFileNameUtf16(&db, i, NULL);

            if (len > tempSize)
            {
                SzFree(NULL, temp);
                tempSize = len;

                temp = (uint16_t *)SzAlloc(NULL, tempSize * sizeof(uint16_t));
                if (!temp)
                {
                    Log("Could not SzAlloc buffer of %d uint16_ts", tempSize);
                    return contents;
                }

                SzArEx_GetFileNameUtf16(&db, i, temp);

                uint64_t fileSize = SzArEx_GetFileSize(&db, i);

                std::string filename = utf16_to_utf8(std::u16string((char16_t *)temp, len));

                contents.push_back(filename);
            }
        }
    }

    SzArEx_Free(&db, &allocImp);
    SzFree(NULL, temp);

    File_Close(&archiveStream.file);

    return contents;
}

std::vector<uint8_t> ExtractFrom7zFile(const std::string &filename, int file_index)
{
    std::vector<uint8_t> buffer;

    CFileInStream archiveStream;
    CLookToRead2 lookStream;
    CSzArEx db;
    SRes res;
    ISzAlloc allocImp;
    ISzAlloc allocTempImp;
    uint16_t *temp = nullptr;
    size_t tempSize = 0;

    allocImp.Alloc = SzAlloc;
    allocImp.Free = SzFree;

    allocTempImp.Alloc = SzAllocTemp;
    allocTempImp.Free = SzFreeTemp;

    {
        WRes wres =
#ifdef UNDER_CE
        InFile_OpenW(&archiveStream.file, filename.c_str()); // change it
#else
        InFile_Open(&archiveStream.file, filename.c_str());
#endif
        if (wres != 0)
        {
            Log("cannot open input file", wres);
            return buffer;
        }
    }

    FileInStream_CreateVTable(&archiveStream);
    archiveStream.wres = 0;
    LookToRead2_CreateVTable(&lookStream, False);
    lookStream.buf = NULL;

    res = SZ_OK;

    {
        lookStream.buf = (Byte *)ISzAlloc_Alloc(&allocImp, kInputBufSize);
        if (!lookStream.buf)
        {
            res = SZ_ERROR_MEM;
            Log("Cannot allocate memory");
        }
        else
        {
            lookStream.bufSize = kInputBufSize;
            lookStream.realStream = &archiveStream.vt;
            LookToRead2_INIT(&lookStream)
        }
    }

    CrcGenerateTable();

    SzArEx_Init(&db);

    if (res == SZ_OK)
    {
        res = SzArEx_Open(&db, &lookStream.vt, &allocImp, &allocTempImp);
    }

    if (res == SZ_OK)
    {
        UInt32 blockIndex = 0xFFFFFFFF; /* it can have any value before first call (if outBuffer = 0) */
        Byte *outBuffer = 0; /* it must be 0 before first call for each new archive. */
        size_t outBufferSize = 0;  /* it can have any value before first call (if outBuffer = 0) */
        size_t offset = 0;
        size_t outSizeProcessed = 0;

        res = SzArEx_Extract(&db, &lookStream.vt, file_index, &blockIndex, &outBuffer, &outBufferSize, &offset, &outSizeProcessed, &allocImp, &allocTempImp);
        if (res != SZ_OK)
        {
            Log("Could not extract file %d (error %d)", file_index, res);
        }
        else
        {
            Log("blockIndex=%d, outBufferSize=%d, outSizeProcessed=%d, offset=%d", blockIndex, outBufferSize, outSizeProcessed, offset);

            buffer.resize(outSizeProcessed);
            //buffer.assign(outBuffer, outBuffer+outBufferSize);

            for (int i = 0; i < outSizeProcessed; i++)
            {
                buffer[i] = outBuffer[i];
            }
        }
    }

    SzArEx_Free(&db, &allocImp);
    SzFree(NULL, temp);

    File_Close(&archiveStream.file);

    return buffer;
}
