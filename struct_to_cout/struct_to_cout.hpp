#pragma once

#include <tuple>

// To tuple
template <class T, class... TArgs>
decltype(void(T{ std::declval<TArgs>()... }), std::true_type{}) test_is_braces_constructible(int);
template <class, class...>
std::false_type test_is_braces_constructible(...);
template <class T, class... TArgs>
using is_braces_constructible = decltype(test_is_braces_constructible<T, TArgs...>(0));

struct any_type {
    template <class T>
    constexpr operator T(); // non explicit
};

// clang-format off
template<class T>
auto to_tuple(T&& object) noexcept {
    using type = std::decay_t<T>;
    if constexpr (is_braces_constructible<type, any_type, any_type, any_type, any_type, any_type, any_type, any_type, any_type, any_type, any_type>{}) {
        auto&& [p1, p2, p3, p4, p5, p6, p7, p8, p9, p10] = object;
        return std::make_tuple(p1, p2, p3, p4, p5, p6, p7, p8, p9, p10);
    } else if constexpr (is_braces_constructible<type, any_type, any_type, any_type, any_type, any_type, any_type, any_type, any_type, any_type>{}) {
        auto&& [p1, p2, p3, p4, p5, p6, p7, p8, p9] = object;
        return std::make_tuple(p1, p2, p3, p4, p5, p6, p7, p8, p9);
    } else if constexpr (is_braces_constructible<type, any_type, any_type, any_type, any_type, any_type, any_type, any_type, any_type>{}) {
        auto&& [p1, p2, p3, p4, p5, p6, p7, p8] = object;
        return std::make_tuple(p1, p2, p3, p4, p5, p6, p7, p8);
    } else if constexpr (is_braces_constructible<type, any_type, any_type, any_type, any_type, any_type, any_type, any_type>{}) {
        auto&& [p1, p2, p3, p4, p5, p6, p7] = object;
        return std::make_tuple(p1, p2, p3, p4, p5, p6, p7);
    } else if constexpr (is_braces_constructible<type, any_type, any_type, any_type, any_type, any_type, any_type>{}) {
        auto&& [p1, p2, p3, p4, p5, p6] = object;
        return std::make_tuple(p1, p2, p3, p4, p5, p6);
    } else if constexpr (is_braces_constructible<type, any_type, any_type, any_type, any_type, any_type>{}) {
        auto&& [p1, p2, p3, p4, p5] = object;
        return std::make_tuple(p1, p2, p3, p4, p5);
    } else if constexpr (is_braces_constructible<type, any_type, any_type, any_type, any_type>{}) {
        auto&& [p1, p2, p3, p4] = object;
        return std::make_tuple(p1, p2, p3, p4);
    } else if constexpr (is_braces_constructible<type, any_type, any_type, any_type>{}) {
        auto&& [p1, p2, p3] = object;
        return std::make_tuple(p1, p2, p3);
    } else if constexpr (is_braces_constructible<type, any_type, any_type>{}) {
        auto&& [p1, p2] = object;
        return std::make_tuple(p1, p2);
    } else if constexpr (is_braces_constructible<type, any_type>{}) {
        auto&& [p1] = object;
        return std::make_tuple(p1);
    } else {
        return std::make_tuple();
    }
}
// clang-format on

namespace __internal {
template <class Ch, class Tr, class Tuple, std::size_t... Is>
void print_tuple_impl(std::basic_ostream<Ch, Tr>& os, const Tuple& t, std::index_sequence<Is...>)
{
    ((os << (Is == 0 ? "" : ", ") << std::get<Is>(t)), ...);
}
} // namespace __internal

// operator for tuple, must without namespace
template <class Ch, class Tr, class... Args>
auto& operator<<(std::basic_ostream<Ch, Tr>& os, const std::tuple<Args...>& t)
{
    os << "{";
    __internal::print_tuple_impl(os, t, std::index_sequence_for<Args...>{});
    return os << "}";
}