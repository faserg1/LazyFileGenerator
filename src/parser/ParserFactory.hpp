#pragma once
#include "IParser.hpp"
#include "ParserSyntax.hpp"
#include <io/IReader.hpp>

namespace lfg::parser
{
    class ParserFactory
    {
    public:
        static IParser::Ptr create(ParserSyntax syntax, io::IReader::Ptr reader, ParseMode mode);
    private:
        ParserFactory() = delete;
    };
}