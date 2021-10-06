#pragma once
#include <source/ISource.hpp>
#include <source/container/SourceContainerBase.hpp>

namespace lfg::source
{
    class Source : public ISource
    {
    public:
        explicit Source(container::SourceContainerBase::Ptr container);

        Iterator begin() override;
        Iterator end() override;
    private:
        container::SourceContainerBase::Ptr container_;
    };
}