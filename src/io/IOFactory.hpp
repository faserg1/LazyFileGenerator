#pragma once
#include "IOTypes.hpp"
#include "IReader.hpp"
#include "IWriter.hpp"
#include <string>

namespace lfg::io
{
    class IOFactory
    {
    public:
        static IReader::Ptr createReader(ReaderType type, std::string file);
        static IWriter::Ptr createWriter(WriterType type, std::string file);
    private:
        IOFactory() = delete;
    };
}