#pragma once
#include <coroutine>

namespace lfg::helper::coroutine
{
    template <class T>
    class Generator
    {
    public:
        struct promise_type;
        class iterator;

        iterator begin() { return iterator{m_coro.done() ? nullptr : this}; }
        iterator end() { return iterator{nullptr}; }
    private:
        promise_type::handle m_coro;
        explicit Generator(promise_type::handle coro) noexcept: m_coro{coro} {}
    };

    template <class T>
    struct Generator<T>::promise_type
    {
        using suspend_never = std::suspend_never;
        using suspend_always = std::suspend_always;
        using handle = std::coroutine_handle<promise_type>;
        using value_type = T;

        value_type value;

        auto get_return_object() noexcept {
            return Generator { handle::from_promise(*this) };
        }

        suspend_never initial_suspend() noexcept { return {}; }
        suspend_always final_suspend() noexcept { return {}; }

        void return_void() noexcept {}

        suspend_always yield_value(T v) noexcept
        {
            value = v;
            return {};
        }

        void unhandled_exception() { std::terminate(); }
    };

    template <class T>
    class Generator<T>::iterator {
    public:
        bool operator != (iterator second) const {
            return m_self != second.m_self;
        }

        iterator & operator++() {
            m_self->m_coro.resume();

            if (m_self->m_coro.done()) {
                m_self = nullptr;
            }
            return *this;
        }

        T operator*() {
            return m_self->m_coro.promise().value;
        }

    private:
        iterator(Generator<T> *self): m_self{self} {}
        Generator<T> *m_self;
        friend class Generator;
    };
}