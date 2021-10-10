#pragma once

#include <memory>
#include <io/IWriter.hpp>
#include <context/IContext.hpp>

namespace lfg::generator::action
{
    class IAction
    {
    public:
        using Ptr = std::shared_ptr<IAction>;
        virtual ~IAction() = default;

        virtual void Write(io::IWriter::Ptr writer, context::IContext::Ptr context) = 0;
    protected:
        IAction() = default;
    };
}