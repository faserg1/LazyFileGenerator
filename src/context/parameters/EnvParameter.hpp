#pragma once

#include "IParameter.hpp"

namespace lfg::context
{
    class EnvParameter : public IParameter
    {
        friend class EnvParameterProvider;
    public:
        EnvParameter(std::string envName, std::string value);
        ParameterType getType() const override;
        std::string getName() const override;
        std::string eval() const override;
    private:
        const std::string name_;
        std::string value_;
    };
}