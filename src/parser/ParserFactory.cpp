#include "ParserFactory.hpp"
#include "ParserAutoconfLike.hpp"
using namespace lfg::parser;

IParser::Ptr ParserFactory::create(ParserSyntax syntax, io::IReader::Ptr reader, ParseMode mode)
{
    switch (syntax)
    {
        case ParserSyntax::Autoconf:
            return std::make_unique<ParserAutoconfLike>(reader, mode);
    }
    return {};
}