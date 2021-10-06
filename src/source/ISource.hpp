#pragma once
#include <memory>
#include <vector>
#include <source/symbol/ISourceSymbol.hpp>
#include <source/SourceIterator.hpp>

namespace lfg::source
{
    class ISource
    {
    public:
        using Ptr = std::shared_ptr<ISource>;
        using Iterator = SourceIterator;
        virtual ~ISource() = default;

        virtual Iterator begin() = 0;
        virtual Iterator end() = 0;
    protected:
        ISource() = default;
    };
}