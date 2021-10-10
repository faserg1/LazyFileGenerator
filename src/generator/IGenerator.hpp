#pragma once
#include <memory>
#include <source/ISource.hpp>
namespace lfg::generator
{
    class IGenerator
    {
    public:
        using Ptr = std::unique_ptr<IGenerator>;
        virtual ~IGenerator() = default;

        virtual void generateAndWrite(source::ISource::Ptr source) = 0;
    protected:
        IGenerator() = default;
    };
}