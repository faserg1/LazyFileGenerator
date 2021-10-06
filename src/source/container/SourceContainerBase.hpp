#pragma once
#include <memory>
#include <source/symbol/ISourceSymbol.hpp>

namespace lfg::source
{
    class SourceIterator;

    namespace container
    {
        class SourceContainerBase
        {
        public:
            struct SourceContainerDataBase
            {
                using Ptr = std::unique_ptr<SourceContainerDataBase>;
                virtual ~SourceContainerDataBase() = default;
            };
        public:
            using Ptr = std::shared_ptr<SourceContainerBase>;
            virtual ~SourceContainerBase() = default;

            virtual bool back(SourceIterator &) = 0;
            virtual bool next(SourceIterator &) = 0;
            virtual SourceIterator copy(SourceIterator &) = 0;

            virtual SourceIterator begin() = 0;
            virtual SourceIterator end() = 0;
        protected:
            void updateIterator(SourceIterator &iter, symbol::ISourceSymbol::Ptr symbol);
            SourceContainerDataBase &getIteratorData(SourceIterator &iter) const;
            SourceIterator createIterator(symbol::ISourceSymbol::Ptr s, container::SourceContainerBase::Ptr c,
                container::SourceContainerBase::SourceContainerDataBase::Ptr d);
            SourceContainerBase() = default;
        };
    }
}