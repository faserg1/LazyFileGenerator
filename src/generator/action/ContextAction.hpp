#pragma once

#include "IAction.hpp"
#include <string>

namespace lfg::generator::action
{
    class ContextAction : public IAction
    {
    public:
        ContextAction(std::string parameterName);

        void write(io::IWriter::Ptr writer, context::IContext::Ptr context) override;
    private:
        std::string parameterName_;
    };
}