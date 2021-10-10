#pragma once

#include "IGenerator.hpp"
#include <io/IWriter.hpp>
#include <context/IContext.hpp>

namespace lfg::generator
{
    class Generator : public IGenerator
    {
    public:
        Generator(io::IWriter::Ptr writer, context::IContext::Ptr context);
        void generateAndWrite(source::ISource::Ptr source) override;
    private:
        io::IWriter::Ptr writer_;
        context::IContext::Ptr context_;
    };
}