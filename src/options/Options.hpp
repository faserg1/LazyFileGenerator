#pragma once
#include <memory>
#include <string>
#include <parser/ParserSyntax.hpp>
#include <run/RunMode.hpp>

namespace lfg::options
{
    class Options
    {
    public:
        Options(int argc, char **argv);
        ~Options();
        bool isValid() const;

        run::RunMode getRunMode() const;

        parser::ParserSyntax getSyntax() const;
        std::string getInputTemplate() const;
        std::string getOutputTemplate() const;
    private:
        struct OptionsData;
        std::unique_ptr<OptionsData> data_;
    };
}

