#include "SourceVectorContainer.hpp"
#include <source/SourceIterator.hpp>
using namespace lfg::source;
using namespace lfg::source::container;

SourceVectorContainer::SourceVectorContainer(SymbolArray arr) : container_(std::move(arr))
{

}

bool SourceVectorContainer::back(SourceIterator &iter)
{
    auto data = getIteratorData(iter);
    return false;
}

bool SourceVectorContainer::next(SourceIterator &iter)
{
    auto data = getIteratorData(iter);
    return false;
}

SourceIterator SourceVectorContainer::copy(SourceIterator &old)
{
    auto *data = dynamic_cast<SourceContainerDataVector*>(&getIteratorData(old));
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