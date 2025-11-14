#pragma once

#include <algorithm>
#include <exception>

class ElementNotFoundException : public std::exception {
    virtual const char* what() const throw() {
        return "ElementNotFoundException";
    }
};

template <typename T>
int easyfind(T& data, int toFind) {
    typename T::iterator it = std::find(data.begin(), data.end(), toFind);

    if (it == data.end())
        throw ElementNotFoundException();
    return *it;
}