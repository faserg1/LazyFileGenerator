#pragma once

#include <string>
#include <vector>

namespace lfg::config
{
    class IConfigProvider
    {
    public:
        virtual std::vector<std::string_view> getDefaultPaths() const = 0;
    };
}