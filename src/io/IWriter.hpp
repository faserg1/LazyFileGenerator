#pragma once
#include <memory>

namespace lfg::io
{
    class IWriter
    {
    public:
        using Ptr = std::shared_ptr<IWriter>;

        virtual ~IWriter() = default;

        virtual size_t write(std::byte *buffer, size_t bufferSize) = 0;
    protected:
        IWriter() = default;
    };
}