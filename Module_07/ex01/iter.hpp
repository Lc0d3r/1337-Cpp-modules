#pragma once 
#include <cstddef>

template <typename T_array>
void iter(T_array* array, size_t length, void (*func)(T_array&)) {
    for (size_t i = 0; i < length; ++i) {
        func(array[i]);
    }
}

template <typename T_array>
void iter(const T_array* array, size_t length, void (*func)(const T_array&)) {
    for (size_t i = 0; i < length; ++i) {
        func(array[i]);
    }
}