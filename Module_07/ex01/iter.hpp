#pragma once 
#include <cstddef>

template <typename T_array, typename F_func>
void iter(T_array* array, size_t length, F_func func) {
    for (size_t i = 0; i < length; ++i) {
        func(array[i]);
    }
}

template <typename T_array, typename F_func>
void iter(const T_array* array, size_t length, F_func func) {
    for (size_t i = 0; i < length; ++i) {
        func(array[i]);
    }
}