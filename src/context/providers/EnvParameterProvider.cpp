#include "EnvParameterProvider.hpp"
using namespace lfg::context;

ParameterType EnvParameterProvider::getType() const
{
    return ParameterType::Environment;
}

IParameter::Ptr EnvParameterProvider::findParameter(const std::string &name)
{
    auto cachedIt = cachedParameters_.find(name);
    if (cachedIt != cachedParameters_.end())
        return cachedIt->second;
    auto paramValue = std::getenv(name.c_str());
    auto param = std::make_shared<EnvParameter>(name, paramValue);
    cachedParameters_.insert(std::make_pair(name, param));
    return param;
}

IParameterProvider::Ptr EnvParameterProvider::create()
{
    return std::unique_ptr<EnvParameterProvider>(new EnvParameterProvider{});
}

