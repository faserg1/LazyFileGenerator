#pragma once
#include "IWriter.hpp"
#include <string>
#include <fstream>

namespace lfg::io
{
    class WriterStd : public IWriter
    {
    public:
        WriterStd(std::string path);
        size_t write(std::byte *buffer, size_t bufferSize) override;
    private:
        std::ofstream stream_;
    };
}