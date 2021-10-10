#include "ContextAction.hpp"
using namespace lfg::generator::action;

ContextAction::ContextAction(std::string parameterName) : parameterName_(parameterName)
{

}

void ContextAction::write(io::IWriter::Ptr writer, context::IContext::Ptr context)
{
    auto param = context->findFirstParameter(parameterName_, {}, false);
    if (param)
    {
        auto value = param->eval();
        writer->write(reinterpret_cast<std::byte*>(value.data()), value.size());
    }
}