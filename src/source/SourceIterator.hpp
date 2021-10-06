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

        reference operator*() const { return *symbol; }
        pointer operator->() { return &*symbol; }

        SourceIterator& operator++() { container->next(*this); return *this; }
        SourceIterator operator++(int) { auto tmp = container->copy(*this); container->next(*this); return tmp; }

        friend bool operator== (const SourceIterator& a, const SourceIterator& b) { return a.symbol == b.symbol; };
        friend bool operator!= (const SourceIterator& a, const SourceIterator& b) { return a.symbol != b.symbol; }; 
    protected:
        SourceIterator(symbol::ISourceSymbol::Ptr s, container::SourceContainerBase::Ptr c,
            container::SourceContainerBase::SourceContainerDataBase::Ptr d) : symbol(s), container(c), containerData(std::move(d)) {}
        symbol::ISourceSymbol::Ptr symbol;
        container::SourceContainerBase::Ptr container;
        container::SourceContainerBase::SourceContainerDataBase::Ptr containerData;
    };
}