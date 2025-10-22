#pragma once 

#include <string>
#include <iostream>
#include <stdexcept>
#include <string>
#include <cstdlib>
#include <limits>
#include <cmath>



class ScalarConverter {
public:
    static void    convert(const std::string& literal);
    ScalarConverter();
    ScalarConverter(const ScalarConverter& other);
    ScalarConverter& operator=(const ScalarConverter& other);
    ~ScalarConverter();
};