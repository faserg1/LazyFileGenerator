#pragma once
#include "ISourceSymbol.hpp"
#include <string>

namespace lfg::source::symbol
{
    class SourceSymbolText : public ISourceSymbol
    {
    public:
        SourceSymbolText(std::string txt);
        const std::string& GetText() const;
        SymbolType GetType() const override;
    private:
        const std::string txt_;
    };
}