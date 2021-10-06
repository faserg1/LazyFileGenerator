#include "ReaderFactory.hpp"
#include "ReaderStd.hpp"
using namespace lfg::io;

IReader::Ptr ReaderFactory::create(ReaderType type, std::string path)
{
    switch (type)
    {
    case ReaderType::StdFilestream:
        return std::make_shared<ReaderStd>(path);
    }
    return {};
}