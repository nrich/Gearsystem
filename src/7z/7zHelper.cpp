/*
 * Gearsystem - Sega Master System / Game Gear Emulator
 * Copyright (C) 2013  Ignacio Sanchez
 * Copyright (C) 2025  Neil Richardson

 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * any later version.

 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see http://www.gnu.org/licenses/
 *
 */

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

std::string utf16_to_utf8(const std::u16string &s)
{
    std::wstring_convert<std::codecvt_utf8_utf16<char16_t>, char16_t> conversion;
    return conversion.to_bytes(s);
}

n7z::Archive::Archive(const std::string &filename)
{
    uint16_t *temp = nullptr;
    size_t temp_size = 0;

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
            Log("cannot open input file (error %d)", wres);
            throw std::runtime_error("Loading " + filename + " failed");
        }
    }

    FileInStream_CreateVTable(&archiveStream);
    archiveStream.wres = 0;
    LookToRead2_CreateVTable(&lookStream, False);
    lookStream.buf = NULL;

    SRes res = SZ_OK;

    {
        lookStream.buf = (Byte *)ISzAlloc_Alloc(&allocImp, kInputBufSize);
        if (!lookStream.buf)
        {
            res = SZ_ERROR_MEM;
            Log("Cannot allocate memory");
            throw std::runtime_error("Cannot allocate memory");
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
    else
    {
        Log("Cannot open archive (Error %d)", res);
        throw std::runtime_error("Cannot open archive");
    }

    if (res == SZ_OK)
    {
        for (size_t i = 0; i < db.NumFiles; i++)
        {
            int is_dir = SzArEx_IsDir(&db, i);

            if (is_dir)
                continue;

            size_t len = SzArEx_GetFileNameUtf16(&db, i, NULL);

            if (len > temp_size)
            {
                SzFree(NULL, temp);
                temp_size = len;

                temp = (uint16_t *)SzAlloc(NULL, temp_size * sizeof(uint16_t));
                if (!temp)
                {
                    Log("Could not SzAlloc buffer of %d uint16_ts", temp_size);
                    throw std::runtime_error("Could not SzAlloc buffer");
                }

                SzArEx_GetFileNameUtf16(&db, i, temp);

                uint64_t file_size = SzArEx_GetFileSize(&db, i);

                std::string path = utf16_to_utf8(std::u16string(reinterpret_cast<char16_t*>(temp), len));

                entries.push_back(n7z::FileEntry{path, file_size, i});
            }
        }
    }

    SzFree(NULL, temp);
}

std::vector<uint8_t> n7z::Archive::extract(const size_t file_index)
{
    std::vector<uint8_t> buffer;

    if (file_index > entries.size())
        return buffer;

    uint32_t block_index = 0xFFFFFFFF; /* it can have any value before first call (if out_buffer = 0) */
    uint8_t *out_buffer = 0; /* it must be 0 before first call for each new archive. */
    size_t out_buffer_size = 0;  /* it can have any value before first call (if out_buffer = 0) */
    size_t offset = 0;
    size_t out_size_processed = 0;

    SRes res = SzArEx_Extract(&db, &lookStream.vt, file_index, &block_index, &out_buffer, &out_buffer_size, &offset, &out_size_processed, &allocImp, &allocTempImp);
    if (res != SZ_OK)
    {
        Log("Could not extract file %d (error %d)", file_index, res);
    }
    else
    {
        Log("block_index=%d, out_buffer_size=%d, out_size_processed=%d, offset=%d", block_index, out_buffer_size, out_size_processed, offset);

        buffer.resize(out_size_processed);
        for (size_t i = 0; i < out_size_processed; i++)
        {
            buffer[i] = out_buffer[i];
        }
    }

    return buffer;
}

n7z::Archive::~Archive()
{
    SzArEx_Free(&db, &allocImp);
    File_Close(&archiveStream.file);
}
