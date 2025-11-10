#pragma once

template <typename T_type>
class Array {
    private:
    T_type*       data_;
    unsigned int  size_;
    public:
    // Constructor
    Array();
    Array(unsigned int size);
    Array(const Array &other);
    Array &operator=(const Array &other);
    ~Array();
    
    unsigned int size() const;
    T_type &operator[](unsigned int index);
    const T_type &operator[](unsigned int index) const;
};

#include "Array.tpp"