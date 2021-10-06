#pragma once
#include "IParser.hpp"
#include <io/IReader.hpp>
#include <source/symbol/ISourceSymbol.hpp>
#include <source/container/SourceContainerBase.hpp>
#include <helper/couroutines/Generator.hpp>
#include <functional>

namespace lfg::parser
{
    class ParserAutoconfLike : public IParser, public std::enable_shared_from_this<ParserAutoconfLike>
    {
        using Container = lfg::source::container::SourceContainerBase::Ptr;
        using Symbol = lfg::source::symbol::ISourceSymbol::Ptr;
        using ParseGen = lfg::helper::coroutine::Generator<Symbol>;
        using GenFunction = std::function<ParseGen()>;
    public:
        ParserAutoconfLike(io::IReader::Ptr reader, ParseMode mode);
        source::ISource::Ptr readSource() override;
    private:
        Container createContainer();
        GenFunction createParserFunction();

        std::vector<Symbol> readSymbols(std::string &buffer, bool &incomplete);
    private:
        io::IReader::Ptr reader_;
        const ParseMode mode_;
    }; 
}
