#include "Source.hpp"
#include <source/SourceIterator.hpp>
using namespace lfg::source;

Source::Source(container::SourceContainerBase::Ptr container) : container_(container)
{

}

Source::Iterator Source::begin()
{
    return container_->begin();
}

Source::Iterator Source::end()
{
    return container_->end();
}