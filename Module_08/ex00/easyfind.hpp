#pragma once

#include <algorithm>
#include <exception>

template <typename T>
typename T::iterator easyfind(T& data, int toFind) {
    typename T::iterator it = std::find(data.begin(), data.end(), toFind);

    if (it == data.end())
       throw std::runtime_error("Value not found in container");
    return it;
}