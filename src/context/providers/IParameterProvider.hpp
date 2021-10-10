#pragma once
#include <memory>
#include <string>
#include <context/parameters/IParameter.hpp>

namespace lfg::context
{
    class IParameterProvider
    {
    public:
        using Ptr = std::unique_ptr<IParameterProvider>;

        virtual ~IParameterProvider() = default;

        virtual ParameterType getType() const = 0;
        virtual IParameter::Ptr findParameter(const std::string &name) = 0;
    };
}