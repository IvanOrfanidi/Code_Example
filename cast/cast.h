#pragma once

#include <tuple>
#include <utility>

template <typename S>
struct cast {
    cast(const S& s)
        : s{ s }
    {
    }
    template <typename T>
    operator T() const { return impl<T>(std::make_index_sequence<std::tuple_size_v<S>>{}); }

    template <typename T>
    T to() const { return impl<T>(std::make_index_sequence<std::tuple_size_v<S>>{}); }

private:
    const S& s;
    template <typename T, size_t... Is>
    T impl(std::index_sequence<Is...>) const { return { std::get<Is>(s)... }; }
};