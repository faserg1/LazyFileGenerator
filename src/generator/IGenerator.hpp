#pragma once
#include <memory>

namespace lfg::generator
{
    class IGenerator
    {
    public:
        using Ptr = std::unique_ptr<IGenerator>;
        virtual ~IGenerator() = default;
    protected:
        IGenerator() = default;
    };
}