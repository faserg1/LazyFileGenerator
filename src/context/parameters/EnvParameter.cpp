#include "EnvParameter.hpp"
using namespace lfg::context;

EnvParameter::EnvParameter(std::string envName, std::string value) :
    name_(envName), value_(value)
{

}

ParameterType EnvParameter::getType() const
{
    return ParameterType::Environment;
}

std::string EnvParameter::getName() const
{
    return name_;
}

std::string EnvParameter::eval() const
{
    return value_;
}