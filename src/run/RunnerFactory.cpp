#include "RunnerFactory.hpp"
#include "RunnerGenerate.hpp"
using namespace lfg::run;
using namespace lfg::options;

IRunner::Ptr RunnerFactory::create(const Options &opts)
{
    auto runMode = opts.getRunMode();
    switch (runMode) {
        case RunMode::Generate:
            return std::make_unique<RunnerGenerate>(
                opts.getInputTemplate(),
                opts.getOutputTemplate(),
                opts.getSyntax());
    }
}