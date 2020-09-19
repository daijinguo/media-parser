#pragma once

#ifndef _INCLUDE_FILE_READER_HPP
#define _INCLUDE_FILE_READER_HPP

#include "types.hpp"

#include <cstdlib>
#include <cstdio>

namespace media{

class FileReader
{
public:
    FileReader();
    ~FileReader();

public:
    bool open(const char* file_name);
    void close();

    int64 getLength();
    int64 getPosition();
    void  setPosition(uint64 pos);

    byte   readByte();
    uint16 read16();
    void   read24(uint24& value);
    uint32 read32();
    uint64 read64();

    size_t skip(uint64 len);
    size_t readBuffer(byte* buffer, size_t len);


private:
    FILE* pfd;
};


}

#endif//_INCLUDE_FILE_READER_HPP
