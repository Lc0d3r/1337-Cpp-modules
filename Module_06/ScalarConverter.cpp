#include "ScalarConverter.hpp"

bool printableChar(char c) {
    return (c >= 32 && c <= 126);
}

bool isDigit(char c) {
    return (c >= '0' && c <= '9');
}

void ScalarConverter::convert(const std::string& literal) {
    double dvalue;
    std::string temp = literal;
    try {
        if (temp == "nan" || temp == "+inf" || temp == "-inf" ||
            temp == "nanf" || temp == "+inff" || temp == "-inff") {
            if (temp.find('f') != std::string::npos) {
                dvalue = strtof(temp.c_str(), 0);
            } else {
                dvalue = strtod(temp.c_str(), 0);
            }
        } else {
            if (temp.find('f') != std::string::npos && temp[temp.length() - 1] == 'f') {
                char *ptr;
                temp[temp.length() - 1] = '\0'; // remove 'f'
                dvalue = strtof(temp.c_str(), &ptr);
                if (*ptr != '\0') {
                    throw std::invalid_argument("Invalid literal for conversion not a float");
                }
            } else if (temp.find('.') != std::string::npos) {
                char *ptr;
                dvalue = strtod(temp.c_str(), &ptr);
                std::cout << "Debug: strtod conversion result = " << dvalue << std::endl;
                if (*ptr != '\0') {
                    throw std::invalid_argument("Invalid literal for conversion not a double");
                }
            } else {
                if (printableChar(temp[0]) && temp.length() == 1 && !isDigit(temp[0])) {
                    dvalue = static_cast<double>(temp[0]);
                } else {
                    char *ptr;
                    dvalue = strtod(temp.c_str(), &ptr);
                    if (*ptr != '\0') {
                        throw std::invalid_argument("Invalid literal for conversion not an integer");
                    }
                }
            }
        }
    } catch (const std::exception& e) {
        std::cerr << "Error converting literal: " << e.what() << std::endl;
        return;
    }

    // Output conversions
    std::cout << "Converting literal: " << literal << std::endl;
    if (dvalue < std::numeric_limits<int>::min() || dvalue > std::numeric_limits<int>::max() || std::isnan(dvalue) || std::isinf(dvalue)) {
        std::cout << "int: impossible" << std::endl;
    } else {
        std::cout << "int: " << static_cast<int>(dvalue) << std::endl;
    }
    if (printableChar(static_cast<char>(dvalue))) {
        std::cout << "char: '" << static_cast<char>(dvalue) << "'" << std::endl;
    } else if (dvalue >= 0 && dvalue <= 127) {
        std::cout << "char: Non displayable" << std::endl;
    } else {
        std::cout << "char: impossible" << std::endl;
    }
    std::cout << "float: " << static_cast<float>(dvalue) << "f" << std::endl;
    std::cout << "double: " << dvalue << std::endl;
}

ScalarConverter::ScalarConverter() {
}

ScalarConverter::ScalarConverter(const ScalarConverter& other) {
    (void)other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) {
    (void)other;
    return *this;
};

ScalarConverter::~ScalarConverter() {};
