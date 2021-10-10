#pragma once
#include <memory>
#include <vector>
#include <context/parameters/IParameter.hpp>

namespace lfg::context
{
    class IContext
    {
    public:
        using Ptr = std::shared_ptr<IContext>;
        using ParameterSearchPriority = std::initializer_list<ParameterType>;

        virtual ~IContext() = default;
        virtual IParameter::Ptr findFirstParameter(const std::string &name, 
            const ParameterSearchPriority &priority, bool strong) const = 0;
    protected:
        IContext() = default;
    };
}