#pragma once

namespace lfg::context
{
    enum class ParameterType
    {
        Environment,
        User, ///< from console or from UI
        Config,
    };
}