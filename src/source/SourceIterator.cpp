#include "SourceIterator.hpp"
using namespace lfg::source;

SourceIterator::SourceIterator(symbol::ISourceSymbol::Ptr s, container::SourceContainerBase::Ptr c,
            container::SourceContainerBase::SourceContainerDataBase::Ptr d) : symbol(s), container(c), containerData(std::move(d))
{
}

SourceIterator::reference SourceIterator::operator*() const
{
    return *symbol;
}

SourceIterator::pointer SourceIterator::operator->()
{
    return &*symbol;
}

SourceIterator& SourceIterator::operator++()
{
    container->next(*this);
    return *this;
}

SourceIterator SourceIterator::operator++(int)
{
    auto tmp = container->copy(*this);
    container->next(*this);
    return tmp;
}

bool SourceIterator::operator== (const SourceIterator& oth)
{
    return symbol == oth.symbol;
}

bool SourceIterator::operator!= (const SourceIterator& oth)
{
    return symbol != oth.symbol;
}