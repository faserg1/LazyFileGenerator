#pragma once

#include <map>
#include <string>
#include "IParameterProvider.hpp"
#include <context/parameters/EnvParameter.hpp>

namespace lfg::context
{
    class EnvParameterProvider : public IParameterProvider
    {
        EnvParameterProvider() = default;
    public:
        ParameterType getType() const override;
        IParameter::Ptr findParameter(const std::string &name) override;
    public:
        static IParameterProvider::Ptr create();
    private:
        std::map<std::string, EnvParameter::Ptr> cachedParameters_;
    };
}