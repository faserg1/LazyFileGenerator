#pragma once
#include <memory>

namespace lfg::context
{
    class IParameter
    {
    public:
        using Ptr = std::shared_ptr<IParameter>;
        virtual ~IParameter() = default;
    protected:
        IParameter() = default;
    };
}