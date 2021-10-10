#pragma once

#include "IAction.hpp"
#include <functional>
#include <string>

namespace lfg::generator::action
{
    class CustomAction : public IAction
    {
    public:
        using ProviderFunction = std::function<const std::string&(context::IContext::Ptr)>;
        CustomAction(ProviderFunction func);

        void Write(io::IWriter::Ptr writer, context::IContext::Ptr context) override;
    private:
        ProviderFunction provider_;
    };
}