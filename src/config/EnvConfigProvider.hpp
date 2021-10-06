#pragma once

#include "IConfigProfider.hpp"

namespace lfg::config
{
    class EnvConfigProvider : public virtual IConfigProvider
    {
    public:
        std::vector<std::string_view> getDefaultPaths() const override;
    };
}