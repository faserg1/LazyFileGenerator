#include "Options.hpp"
#include <cxxopts.hpp>

using namespace lfg::options;
using namespace lfg::run;
using namespace lfg::parser;

struct Options::OptionsData
{
    cxxopts::ParseResult result;
};

Options::Options(int argc, char **argv)
{
    data_ = std::make_unique<OptionsData>();
    cxxopts::Options options("LazyFileGenerrator", "A file generater, where you can use programmable templates");
    options.add_options()
        ("s,syntax", "Use syntax: [Autoconf,...]", cxxopts::value<std::string>())
        ("i,input", "Path to input template", cxxopts::value<std::string>())
        ("o,output", "Path to output file", cxxopts::value<std::string>());
    data_->result = options.parse(argc, argv);
}

Options::~Options() = default;

bool Options::isValid() const
{
    return true;
}

RunMode Options::getRunMode() const
{
    return RunMode::Generate;
}

ParserSyntax Options::getSyntax() const
{
    auto strStx = data_->result["syntax"];
    if (strStx.as<std::string>() == "autoconf")
        return ParserSyntax::Autoconf;
    return ParserSyntax::Invalid;
}

std::string Options::getInputTemplate() const
{
    return data_->result["input"].as<std::string>();
}

std::string Options::getOutputTemplate() const
{
    return data_->result["output"].as<std::string>();
}