#pragma once 

#include <vector>
#include <algorithm>
#include <stdexcept>
#include <limits>
#include <iostream>


class Span {
   public:
    Span(unsigned int n);
    Span(const Span &other);
    Span &operator=(const Span &other);
    ~Span();
    class ThereIsNoSpaceLeft : public std::exception {
        const char *what() const throw ();
    };

    class NoSpanCanBeFound : public std::exception {
        const char *what() const throw ();
    };

    void addNumber(int number);
    void addNumbers(std::vector<int>::iterator first, std::vector<int>::iterator last);

    unsigned int shortestSpan() ;
    unsigned int longestSpan() ;
    void printNumbers() ;

   private:
    unsigned int maxSize;
    std::vector<int> numbers;
};