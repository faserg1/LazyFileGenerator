#pragma once
#include <memory>
#include "Buffer.hpp"

namespace lfg::io
{
    class IReader
    {
    public:
        using Ptr = std::shared_ptr<IReader>;

        virtual ~IReader() = default;
        virtual size_t read(std::byte *dst, size_t bufferSize) = 0;
        template <size_t BufferSize>
        Buffer<BufferSize> read()
        {
            Buffer<BufferSize> buffer;
            buffer.actualSize = read(buffer.data.data(), BufferSize);
            return std::move(buffer);
        }
    protected:
        IReader() = default;
    };
}