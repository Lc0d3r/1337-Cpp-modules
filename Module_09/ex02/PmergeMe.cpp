#include "PmergeMe.hpp"

void containsOnlyDigits(const std::string& str) {
    if (str.empty())
        throw std::invalid_argument("Error: Empty argument found");
    if (str.find_first_not_of("0123456789") != std::string::npos)
        throw std::invalid_argument("Error: Non-digit character found");
    if (str.length() > 10 || (str.length() == 10 && str > "2147483647"))
        throw std::out_of_range("Error: Integer value out of range");
    if (str[0] == '0' && str.length() > 1)
        throw std::invalid_argument("Error: Leading zeros are not allowed");
    if (str.length() == 1 && str[0] == '0')
        throw std::invalid_argument("Error: Zero is not allowed");
}

void errorCheck(int size, char **str) {
    if (size < 2)
        throw std::invalid_argument("Error: Use the program like this => ./PmergeMe \"some ints\"");
    for (int i = 1; i < size; ++i) {
        // std::cout << str[i] << std::endl;
        containsOnlyDigits(str[i]);
    }
}