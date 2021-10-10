#include "RunnerGenerate.hpp"
#include <io/IOFactory.hpp>
#include <parser/ParserFactory.hpp>
#include <source/ISource.hpp>
using namespace lfg::run;
using namespace lfg::io;
using namespace lfg::parser;

RunnerGenerate::RunnerGenerate(std::string in, std::string out, ::lfg::parser::ParserSyntax syntax) :
    in_(in), out_(out), syntax_(syntax)
{

}

void RunnerGenerate::run()
{
    auto reader = IOFactory::createReader(io::ReaderType::StdFilestream, in_);
    auto parser = ParserFactory::create(syntax_, reader, ParseMode::Normal);
    auto source = parser->readSource();
    for (auto &sym : *source)
    {

    }
}