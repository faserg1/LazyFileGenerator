#pragma once
#include <memory>
#include <vector>
#include "IParameter.hpp"

namespace lfg::context
{
    class IContext
    {
    public:
        using Ptr = std::shared_ptr<IContext>;

        virtual ~IContext() = default;
        virtual std::vector<IParameter::Ptr> getParameters() = 0;
    protected:
        IContext() = default;
    };
}