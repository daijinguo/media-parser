#include "basic/filereader.hpp"

namespace media {

FileReader::FileReader(): pfd{nullptr} {
}

FileReader::~FileReader() {
    close();
}

void FileReader::close()
{
    if(nullptr != pfd)
    {
        fclose(pfd);
        pfd = nullptr;
    }
}

bool FileReader::open(const char *file_name)
{
    pfd = fopen(file_name, "rb");
    if(nullptr == pfd)
        return false;
    return true;
}

int64 FileReader::getLength()
{
    if(nullptr == pfd)
        return 0;
    int64 current = ftell(pfd);
    fseek(pfd, 0, SEEK_END);
    int64 file_size = ftell(pfd);
    fseek(pfd, current, SEEK_SET);
    return file_size;
}

int64 FileReader::getPosition() {
    if(nullptr == pfd)
        return 0;
    return ftell(pfd);
}

void FileReader::setPosition(uint64 pos) {
    fseek(pfd, pos, SEEK_SET);
}

byte FileReader::readByte() {
    byte ret{0};
    fread(&ret, 1, 1, pfd);
    return ret;
}

uint16 FileReader::read16() {
    uint16 data{0};
    fread(&data, sizeof(uint16), 1, pfd);
    return data;
}

void FileReader::read24(uint24& value) {
    fread(&value.value, 3, 1, pfd);
}

uint32 FileReader::read32() {
    uint32 data{0};
    fread(&data, sizeof(uint32), 1, pfd);
    return data;
}

uint64 FileReader::read64() {
    uint64 data{0};
    fread(&data, sizeof(data), 1, pfd);
    return data;
}


size_t FileReader::skip(uint64 len) {
    return fseek(pfd, len, SEEK_CUR);
}

size_t FileReader::readBuffer(byte* buffer, size_t len) {
    return fread(buffer, 1, len, pfd);
}


}
