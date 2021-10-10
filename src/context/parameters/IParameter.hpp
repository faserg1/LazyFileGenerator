#pragma once
#include <memory>
#include <string>
#include "ParameterType.hpp"

namespace lfg::context
{
    class IParameter
    {
    public:
        using Ptr = std::shared_ptr<IParameter>;
        virtual ~IParameter() = default;
        virtual ParameterType getType() const = 0;
        virtual std::string getName() const = 0;
        virtual std::string eval() const = 0;
    protected:
        IParameter() = default;
    };
}