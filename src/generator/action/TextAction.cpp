#include "TextAction.hpp"
using namespace lfg::generator::action;

TextAction::TextAction(std::string txt) : txt_(txt)
{

}

void TextAction::Write(io::IWriter::Ptr writer, context::IContext::Ptr)
{
    writer->write(reinterpret_cast<std::byte*>(txt_.data()), txt_.size());
}