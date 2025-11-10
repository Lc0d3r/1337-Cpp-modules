#pragma once 
#include <cstddef>

template <typename T_array, typename T_function>
void iter(T_array* array, size_t length, T_function func) {
    for (size_t i = 0; i < length; ++i) {
        func(array[i]);
    }
}

template <typename T_array, typename T_function>
void iter(const T_array* array, size_t length, T_function func) {
    for (size_t i = 0; i < length; ++i) {
        func(array[i]);
    }
}