#pragma once
#include "IReader.hpp"
#include <string>
#include <fstream>

namespace lfg::io
{
    class ReaderStd : public IReader
    {
    public:
        ReaderStd(std::string path);
        size_t read(std::byte *buffer, size_t bufferSize) override;
    private:
        std::ifstream stream_;
        bool eof = false;
    };
}