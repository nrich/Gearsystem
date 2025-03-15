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

#ifndef _7ZHELPER_H
#define	_7ZHELPER_H

#include <list>
#include <string>
#include <vector>
#include <cstdint>

#include "Precomp.h"
#include "7z.h"
#include "7zAlloc.h"
#include "7zBuf.h"
#include "7zCrc.h"
#include "7zFile.h"
#include "7zVersion.h"

namespace n7z
{
    struct FileEntry
    {
        std::string filepath;
        uint64_t size;
        size_t index;
    };

    class Archive
    {
        std::list<FileEntry> entries;

        CFileInStream archiveStream;
        CLookToRead2 lookStream;
        CSzArEx db;

        ISzAlloc allocImp;
        ISzAlloc allocTempImp;
    public:
        Archive(const std::string &filename);
        const std::list<FileEntry> list() const
        {
            return entries;
        }

        std::vector<uint8_t> extract(const size_t file_index);

        ~Archive();
    };

}; // n7z 

#endif	/* _7ZHELPER_H */
