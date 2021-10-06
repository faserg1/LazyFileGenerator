#pragma once
#include "ReaderType.hpp"
#include "IReader.hpp"
#include <string>

namespace lfg::io
{
    class ReaderFactory
    {
    public:
        static IReader::Ptr create(ReaderType type, std::string file);
    private:
        ReaderFactory() = delete;
    };
}