#include "SourceVectorContainer.hpp"
#include <source/SourceIterator.hpp>
using namespace lfg::source;
using namespace lfg::source::container;

SourceVectorContainer::SourceVectorContainer(SymbolArray arr) : container_(std::move(arr))
{

}

bool SourceVectorContainer::back(SourceIterator &iter)
{
    auto data = getIteratorData<SourceContainerDataVector>(iter);
    data->iter--;
    updateIterator(iter, *data->iter);
    return true;
}

bool SourceVectorContainer::next(SourceIterator &iter)
{
    auto data = getIteratorData<SourceContainerDataVector>(iter);
    data->iter++;
    source::symbol::ISourceSymbol::Ptr sym = {};
    if (data->iter != container_.end())
        sym = *data->iter;
    updateIterator(iter, sym);
    return true;
}

SourceIterator SourceVectorContainer::copy(SourceIterator &old)
{
    auto data = getIteratorData<SourceContainerDataVector>(old);
    auto newData = std::make_unique<SourceContainerDataVector>();
    newData->iter = data->iter;
    return createIterator(*container_.begin(), shared_from_this(), std::move(newData));
}

SourceIterator SourceVectorContainer::begin()
{
    auto newData = std::make_unique<SourceContainerDataVector>();
    newData->iter = container_.begin();
    return createIterator(*container_.begin(), shared_from_this(), std::move(newData));
}

SourceIterator SourceVectorContainer::end()
{
    auto newData = std::make_unique<SourceContainerDataVector>();
    newData->iter = container_.end();
    return createIterator({}, shared_from_this(), std::move(newData));
}