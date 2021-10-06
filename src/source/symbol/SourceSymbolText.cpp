#include "SourceSymbolText.hpp"
using namespace lfg::source::symbol;

SourceSymbolText::SourceSymbolText(std::string txt) : txt_(std::move(txt))
{

}

const std::string& SourceSymbolText::GetText() const
{
    return txt_;
}

SymbolType SourceSymbolText::GetType() const
{
    return SymbolType::Text;
}