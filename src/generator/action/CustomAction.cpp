#include "CustomAction.hpp"
using namespace lfg::generator::action;

CustomAction::CustomAction(ProviderFunction func) : provider_(func)
{

}

void CustomAction::write(io::IWriter::Ptr writer, context::IContext::Ptr context)
{
    auto result = provider_(context);
    writer->write(reinterpret_cast<std::byte*>(result.data()), result.size());
}