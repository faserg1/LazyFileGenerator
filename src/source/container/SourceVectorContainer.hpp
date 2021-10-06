#pragma once
#include "SourceContainerBase.hpp"
#include <source/symbol/ISourceSymbol.hpp>
#include <vector>

namespace lfg::source::container
{
    class SourceVectorContainer : public SourceContainerBase, public std::enable_shared_from_this<SourceVectorContainer>
    {
        using Symbol = ::lfg::source::symbol::ISourceSymbol::Ptr;
        using SymbolArray = std::vector<Symbol>;
        struct SourceContainerDataVector : SourceContainerDataBase
        {
            using InternalIter = SymbolArray::iterator;

            InternalIter iter; 
        };
    public:
        SourceVectorContainer(SymbolArray arr);
        bool back(SourceIterator &) override;
        bool next(SourceIterator &) override;
        SourceIterator copy(SourceIterator &) override;

        SourceIterator begin() override;
        SourceIterator end() override;
    private:
        SymbolArray container_;
    };
}