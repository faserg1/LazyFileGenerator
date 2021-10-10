#include "SourceSymbolParameter.hpp"
#include <generator/action/ContextAction.hpp>
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

SourceSymbolParameter::ActionArray SourceSymbolParameter::getActions() const
{
    return {std::make_shared<generator::action::ContextAction>(name_)};
}