#pragma once
#include <memory>

namespace lfg::converter
{
    class IConverter
    {
    public:
        using Ptr = std::unique_ptr<IConverter>;
        virtual ~IConverter() = default;
    protected:
        IConverter() = default;
    };
}