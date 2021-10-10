#pragma once

#include "IAction.hpp"
#include <string>

namespace lfg::generator::action
{
    class TextAction : public IAction
    {
    public:
        TextAction(std::string txt);

        void Write(io::IWriter::Ptr writer, context::IContext::Ptr context) override;
    private:
        std::string txt_;
    };
}