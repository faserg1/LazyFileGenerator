#include "ContextAction.hpp"
using namespace lfg::generator::action;

ContextAction::ContextAction(std::string parameterName) : parameterName_(parameterName)
{

}

void ContextAction::Write(io::IWriter::Ptr writer, context::IContext::Ptr context)
{
    auto value = context->findFirstParameter(parameterName_, {}, false);
}