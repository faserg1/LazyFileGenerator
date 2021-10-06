#include "ParserAutoconfLike.hpp"
#include <source/Source.hpp>
#include <source/container/SourceVectorContainer.hpp>
#include <source/symbol/SourceSymbolText.hpp>
#include <source/symbol/SourceSymbolParameter.hpp>
#include <regex>
#include <deque>
#include <algorithm>
#include <stdexcept>

using namespace lfg::parser;
using namespace lfg::source;

namespace lfg::parser
{
    namespace
    {
        const auto paramSearch = std::regex("@[_a-zA-Z][_a-zA-Z0-9]*@", std::regex::ECMAScript | std::regex::optimize);
    }
}

ParserAutoconfLike::ParserAutoconfLike(io::IReader::Ptr reader, ParseMode mode)
    : reader_(reader), mode_(mode)
{

}

ISource::Ptr ParserAutoconfLike::readSource()
{
    return std::make_shared<source::Source>(createContainer());
}

ParserAutoconfLike::Container ParserAutoconfLike::createContainer()
{
    switch (mode_)
    {
    case ParseMode::Normal:
    {
        std::vector<lfg::source::symbol::ISourceSymbol::Ptr> arr;
        auto genFunction = createParserFunction();
        for (auto symbol : genFunction())
            arr.push_back(symbol);
        return std::make_shared<container::SourceVectorContainer>(std::move(arr));
    }
        
    }
    return {};
}

ParserAutoconfLike::GenFunction ParserAutoconfLike::createParserFunction()
{
    auto gen = [self = shared_from_this()]() -> ParseGen
    {
        constexpr auto bufferSize = 1024;
        std::string currentString{};
        bool incomplete = false;
        do {
            auto buffer = self->reader_->read<bufferSize>();
            if (buffer.actualSize == 0)
                break;

            currentString += std::string(reinterpret_cast<char*>(buffer.data.data()), buffer.actualSize);

            for (auto sym : self->readSymbols(currentString, incomplete))
                co_yield sym;
        } while (true);
        if (incomplete)
            throw std::runtime_error("Invalid syntax!");
    };
    return GenFunction(gen);
}

std::vector<ParserAutoconfLike::Symbol> ParserAutoconfLike::readSymbols(std::string &buffer, bool &incomplete)
{
    std::vector<ParserAutoconfLike::Symbol> symbols;
    std::smatch sm;
    while (std::regex_search(buffer, sm, paramSearch))
    {
        auto txt = std::string(sm.prefix());
        if (txt.size())
            symbols.push_back(std::make_shared<lfg::source::symbol::SourceSymbolText>(std::move(txt)));
        auto name = sm.str();
        name = name.substr(1, name.size() - 2);
        symbols.push_back(std::make_shared<lfg::source::symbol::SourceSymbolParameter>(std::move(name)));
        buffer = sm.suffix();
    }
    incomplete = (buffer.find('@') != buffer.npos);
    return std::move(symbols);
}