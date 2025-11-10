#include "Array.hpp"

template <typename T_type>
Array<T_type>::Array() : data_(NULL), size_(0) {}

template <typename T_type>
Array<T_type>::Array(unsigned int size) : size_(size) {
    data_ = new T_type[size_];
    for (unsigned int i = 0; i < size_; ++i) {
        data_[i] = T_type();
    }
}

template <typename T_type>
Array<T_type>::Array(const Array &other) : size_(other.size_) {
    data_ = new T_type[size_];
    for (unsigned int i = 0; i < size_; ++i) {
        data_[i] = other.data_[i];
    }
}

template <typename T_type>
Array<T_type> &Array<T_type>::operator=(const Array &other) {
    if (this != &other) {
        delete[] data_;
        size_ = other.size_;
        data_ = new T_type[size_];
        for (unsigned int i = 0; i < size_; ++i) {
            data_[i] = other.data_[i];
        }
    }
    return *this;
}

template <typename T_type>
Array<T_type>::~Array() {
    delete[] data_;
}

template <typename T_type>
unsigned int Array<T_type>::size() const {
    return size_;
}

template <typename T_type>
T_type &Array<T_type>::operator[](unsigned int index) {
    if (index >= size_) {
        throw std::out_of_range("Index out of bounds");
    }
    return data_[index];
}

template <typename T_type>
const T_type &Array<T_type>::operator[](unsigned int index) const {
    if (index >= size_) {
        throw std::out_of_range("Index out of bounds");
    }
    return data_[index];
}