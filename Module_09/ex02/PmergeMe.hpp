#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
#include <exception>
#include <string>
#include <ctime> 

void containsOnlyDigits(const std::string& str);
void errorCheck(int size, char **str);
double sort_vect(int size, char **str);

// implementation
template <typename T>
T fordJohnsonVect(T &input) {
    if (input.size() <= 1) return input;

    T largers;
    T smalls;

    for (size_t i = 0; i < input.size(); i+=2) {
        if (i+1 >= input.size())
            smalls.push_back(input[i]);
        else {
            if (input[i] <= input[i+1]) {
                smalls.push_back(input[i]);
                largers.push_back(input[i+1]);
            } else if (input[i] > input[i+1]) {
                largers.push_back(input[i]);
                smalls.push_back(input[i+1]);
            }
        }
    }
    // recursion
    largers = fordJohnsonVect(largers);
    // the insertion part
    for (size_t i = 0; i < smalls.size(); ++i) {
        typename T::iterator pos = std::lower_bound(largers.begin(), largers.end(), smalls[i]);
        largers.insert(pos, smalls[i]);
    }
    return largers;
}

template <typename T>
double sort_vect(int size, char **str, bool print) {
    clock_t start = clock();
    T vect;
    T res;
    for (int i = 1; i < size; ++i) {
        vect.push_back(std::atol(str[i]));
    }
    res = fordJohnsonVect<T>(vect);
    clock_t end = clock();
    if (print) {
        std::cout << "Before: " ;
        for (size_t i = 0; i < vect.size(); ++i) {
            std::cout << vect[i] << " ";
        }
        std::cout << std::endl;
        std::cout << "After: " ;
        for (size_t i = 0; i < res.size(); ++i) {
            std::cout << res[i] << " ";
        }
        std::cout << std::endl;
    }
    double time_mc = (double)(end - start) / CLOCKS_PER_SEC * 1000000;
    return time_mc;
}