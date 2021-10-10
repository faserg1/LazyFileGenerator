#include "IOFactory.hpp"
#include "ReaderStd.hpp"
#include "WriterStd.hpp"
using namespace lfg::io;

IReader::Ptr IOFactory::createReader(ReaderType type, std::string path)
{
    switch (type)
    {
    case ReaderType::StdFilestream:
        return std::make_shared<ReaderStd>(path);
    }
    return {};
}

IWriter::Ptr IOFactory::createWriter(WriterType type, std::string path)
{
    switch (type)
    {
    case WriterType::StdFilestream:
        return std::make_shared<WriterStd>(path);
    }
    return {};
}