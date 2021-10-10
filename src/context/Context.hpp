#pragma once
#include "IContext.hpp"
#include <context/providers/IParameterProvider.hpp>

namespace lfg::context
{
    class Context : public IContext
    {
    public:
        Context();

        void addProvider(IParameterProvider::Ptr parameterProvider);
        IParameter::Ptr findFirstParameter(const std::string &name, 
            const ParameterSearchPriority &priority, bool strong) const override;
    private:
        std::vector<IParameterProvider::Ptr> providers_;
    };
}