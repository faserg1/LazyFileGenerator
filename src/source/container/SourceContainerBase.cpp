#include "SourceContainerBase.hpp"
#include <source/SourceIterator.hpp>
using namespace lfg::source;
using namespace lfg::source::symbol;
using namespace lfg::source::container;

void SourceContainerBase::updateIterator(SourceIterator &iter, ISourceSymbol::Ptr symbol)
{
    iter.symbol = symbol;
}

SourceIterator SourceContainerBase::createIterator(ISourceSymbol::Ptr s, SourceContainerBase::Ptr c,
    SourceContainerBase::SourceContainerDataBase::Ptr d)
{
    return SourceIterator(s, c, std::move(d));
}

SourceContainerBase::SourceContainerDataBase *SourceContainerBase::internalGetContainerData(SourceIterator &iter) const
{
    return &*iter.containerData;
}