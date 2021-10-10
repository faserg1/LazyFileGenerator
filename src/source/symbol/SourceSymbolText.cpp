#include "SourceSymbolText.hpp"
#include <generator/action/TextAction.hpp>
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

SourceSymbolText::ActionArray SourceSymbolText::getActions() const
{
    return {std::make_shared<generator::action::TextAction>(txt_)};
}