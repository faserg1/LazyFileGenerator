#pragma once
#include <memory>

namespace lfg::run
{
    class IRunner
    {
    public:
        using Ptr = std::unique_ptr<IRunner>;
        virtual ~IRunner() = default;

        virtual void run() = 0;
    protected:
        IRunner() = default;
    };
}