#include "ReaderStd.hpp"
using namespace lfg::io;

ReaderStd::ReaderStd(std::string path) : stream_(path.c_str())
{
}

size_t ReaderStd::read(std::byte *buffer, size_t bufferSize)
{
    if (stream_.eof() || eof)
        return 0;
    stream_.read(reinterpret_cast<char*>(buffer), bufferSize);
    if (stream_.eof()) {
        eof = true;
    }
    return stream_.gcount();
}