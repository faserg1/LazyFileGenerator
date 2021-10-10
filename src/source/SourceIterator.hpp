#pragma once
#include <iterator>
#include <source/symbol/ISourceSymbol.hpp>
#include <source/container/SourceContainerBase.hpp>

namespace lfg::source
{
    class SourceIterator
    {
        friend container::SourceContainerBase;
    public:
        using iterator_category = std::forward_iterator_tag;
        using difference_type   = std::ptrdiff_t;
        using value_type        = symbol::ISourceSymbol::Ptr;
        using reference         = symbol::ISourceSymbol&;
        using pointer           = symbol::ISourceSymbol*;

        reference operator*() const;
        pointer operator->();

        SourceIterator& operator++();
        SourceIterator operator++(int);

        bool operator== (const SourceIterator&);
        bool operator!= (const SourceIterator&);
    protected:
        SourceIterator(symbol::ISourceSymbol::Ptr s, container::SourceContainerBase::Ptr c,
            container::SourceContainerBase::SourceContainerDataBase::Ptr d);
        symbol::ISourceSymbol::Ptr symbol;
        container::SourceContainerBase::Ptr container;
        container::SourceContainerBase::SourceContainerDataBase::Ptr containerData;
    };
}