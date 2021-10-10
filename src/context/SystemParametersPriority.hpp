#pragma once
#include <utility>
#include <context/parameters/ParameterType.hpp>

namespace lfg::context
{
    constexpr auto SystemParametersPriority = {
        ParameterType::Environment,
        ParameterType::Config,
        ParameterType::User,
    };
}