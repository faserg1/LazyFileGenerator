#pragma once
#include <memory>

namespace lfg::io
{
    class IWriter
    {
    public:
        using Ptr = std::shared_ptr<IWriter>;

        virtual ~IWriter() = default;
    protected:
        IWriter() = default;
    };
}