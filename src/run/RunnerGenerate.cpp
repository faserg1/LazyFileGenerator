#include "RunnerGenerate.hpp"
#include <io/ReaderFactory.hpp>
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
    auto reader = ReaderFactory::create(io::ReaderType::StdFilestream, in_);
    auto parser = ParserFactory::create(syntax_, reader, ParseMode::Normal);
    auto source = parser->readSource();
    for (auto &sym : *source)
    {

    }
}