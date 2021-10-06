#pragma once
#include <memory>
#include "SymbolType.hpp"

namespace lfg::source::symbol
{
    class ISourceSymbol
    {
    public:
        using Ptr = std::shared_ptr<ISourceSymbol>;
        virtual ~ISourceSymbol() = default;
        virtual SymbolType GetType() const = 0;
    protected:
        ISourceSymbol() = default;
    };
}