#pragma once
#include <memory>
#include <source/ISource.hpp>

namespace lfg::parser
{
    enum class ParseMode
    {
        Normal,
        Lazy
    };

    class IParser
    {
    public:
        using Ptr = std::shared_ptr<IParser>;
        virtual ~IParser() = default;

        virtual source::ISource::Ptr readSource() = 0;
    protected:
        IParser() = default;
    };
}