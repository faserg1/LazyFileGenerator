#pragma once
#include "ISourceSymbol.hpp"
#include <string>

namespace lfg::source::symbol
{
    class SourceSymbolParameter : public ISourceSymbol
    {
    public:
        SourceSymbolParameter(std::string name);
        const std::string& GetName() const;
        SymbolType GetType() const override;
    private:
        const std::string name_;
    };
}