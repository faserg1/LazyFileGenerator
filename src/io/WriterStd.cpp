#include "WriterStd.hpp"
using namespace lfg::io;

WriterStd::WriterStd(std::string path) : stream_(path.c_str(), std::ios_base::trunc)
{
}

size_t WriterStd::write(std::byte *buffer, size_t bufferSize)
{
    auto was = stream_.tellp();
    stream_.write(reinterpret_cast<char*>(buffer), bufferSize);
    return stream_.tellp() - was;
}