#pragma once
#include "IRunner.hpp"
#include <string>
#include <parser/ParserSyntax.hpp>

namespace lfg::run
{
    class RunnerGenerate : public IRunner
    {
    public:
        RunnerGenerate(std::string in, std::string out, ::lfg::parser::ParserSyntax syntax);

        void run() override;
    private:
        const std::string in_;
        const std::string out_;
        const ::lfg::parser::ParserSyntax syntax_;
    };
}