#include "SourceSymbolParameter.hpp"
using namespace lfg::source::symbol;

SourceSymbolParameter::SourceSymbolParameter(std::string name) : name_(std::move(name))
{

}

const std::string& SourceSymbolParameter::GetName() const
{
    return name_;
}

SymbolType SourceSymbolParameter::GetType() const
{
    return SymbolType::Parameter;
}