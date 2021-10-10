#include "RunnerGenerate.hpp"
#include <io/IOFactory.hpp>
#include <parser/ParserFactory.hpp>
#include <source/ISource.hpp>
#include <generator/Generator.hpp>
#include <context/Context.hpp>
using namespace lfg::run;
using namespace lfg::io;
using namespace lfg::parser;
using namespace lfg::generator;
using namespace lfg::context;

RunnerGenerate::RunnerGenerate(std::string in, std::string out, ::lfg::parser::ParserSyntax syntax) :
    in_(in), out_(out), syntax_(syntax)
{

}

void RunnerGenerate::run()
{
    auto reader = IOFactory::createReader(io::ReaderType::StdFilestream, in_);
    auto parser = ParserFactory::create(syntax_, reader, ParseMode::Normal);
    auto source = parser->readSource();
    auto writer = IOFactory::createWriter(io::WriterType::StdFilestream, out_);
    auto ctx = std::make_shared<Context>();
    auto gen = std::make_shared<Generator>(writer, ctx);
    gen->generateAndWrite(source);
}