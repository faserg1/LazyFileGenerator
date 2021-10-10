#pragma once
#include <memory>
#include <vector>
#include "SymbolType.hpp"
#include <generator/action/IAction.hpp>

namespace lfg::source::symbol
{
    class ISourceSymbol
    {
    public:
        using Ptr = std::shared_ptr<ISourceSymbol>;
        using ActionArray = std::vector<generator::action::IAction::Ptr>;
        virtual ~ISourceSymbol() = default;
        virtual SymbolType GetType() const = 0;
        virtual ActionArray getActions() const = 0;
    protected:
        ISourceSymbol() = default;
    };
}