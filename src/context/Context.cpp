#include "Context.hpp"
#include <context/SystemParametersPriority.hpp>
#include <context/providers/EnvParameterProvider.hpp>
#include <algorithm>
#include <set>
using namespace lfg::context;

Context::Context()
{
    addProvider(EnvParameterProvider::create());
}

void Context::addProvider(IParameterProvider::Ptr parameterProvider)
{
    providers_.push_back(std::move(parameterProvider));
}

IParameter::Ptr Context::findFirstParameter(const std::string &name,
    const ParameterSearchPriority &priority, bool strong) const
{
    std::set<ParameterType> stdPriority = SystemParametersPriority;

    auto findInPriority = [name, this](ParameterType type) -> IParameter::Ptr
    {
        auto it = std::find_if(providers_.begin(), providers_.end(), 
            [type](auto &prov){return prov->getType() == type;});
        if (it == providers_.end())
            return {};
        return (*it)->findParameter(name);
    };

    for (auto searchIn : priority)
    {
        stdPriority.erase(searchIn);
        if (auto param = findInPriority(searchIn))
            return param;
    }
    for (auto searchIn : stdPriority)
    {
        if (auto param = findInPriority(searchIn))
            return param;
    }
    return {};
}