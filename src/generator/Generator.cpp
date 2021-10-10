#include "Generator.hpp"
#include <source/symbol/ISourceSymbol.hpp>
#include <generator/action/IAction.hpp>
using namespace lfg::generator;

Generator::Generator(io::IWriter::Ptr writer, context::IContext::Ptr context) : writer_(writer), context_(context)
{
}

void Generator::generateAndWrite(source::ISource::Ptr source)
{
    for (auto &sym : *source)
    {
        auto actions = sym.getActions();
        for (auto &action : actions)
        {
            action->write(writer_, context_);
        }
    }
}