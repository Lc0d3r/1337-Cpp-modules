#pragma once

#include <algorithm>
#include <exception>

template <typename T>
int easyfind(T& data, int toFind) {
    typename T::iterator it = std::find(data.begin(), data.end(), toFind);

    if (it == data.end())
        throw std::out_of_range("Value not found");
    return *it;
}