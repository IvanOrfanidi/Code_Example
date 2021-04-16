#pragma once

#include <boost/type_index.hpp>

template <typename T>
auto getType(const T&)
{
    return boost::typeindex::type_id_with_cvr<T>().pretty_name();
}

template <typename T>
auto getParamType(const T& param)
{
    return boost::typeindex::type_id_with_cvr<decltype(param)>().pretty_name();
}
