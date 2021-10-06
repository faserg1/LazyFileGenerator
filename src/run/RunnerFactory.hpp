#pragma once
#include "IRunner.hpp"
#include "RunMode.hpp"
#include <options/Options.hpp>

namespace lfg::run
{
    class RunnerFactory
    {
    public:
        static IRunner::Ptr create(const options::Options &opts);
    private:
        RunnerFactory() = delete;
    };
}