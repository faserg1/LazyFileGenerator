#pragma once
#include <array>

namespace lfg::io
{
    template <size_t BufferSize>
    struct Buffer
    {
        std::array<std::byte, BufferSize> data;
        size_t actualSize;
    };
}
