#include "RPN.hpp"

void evaluateRPN(char *str) {
    std::list<int> stack;
    std::stringstream ss;

    ss << str;

    int number;
    std::string input;
    while (ss >> input) {
        // parse
        if (input.size() > 1)
            throw std::runtime_error("Error");
        if (!isdigit(input[0]) && input[0] != '+' && input[0] != '-' && input[0] != '*' && input[0] != '/')
            throw std::runtime_error("Error");
        if (isdigit(input[0])) {
            number = input[0] - '0';
            stack.push_back(number);
        }
        else {
            // parse
            if (stack.size() < 2)   
                throw std::runtime_error("Error");
            int right = stack.back();
            stack.pop_back();
            int left = stack.back();
            stack.pop_back();
            switch (input[0]) {
                case '+':
                    stack.push_back(left+right);
                    break;
                case '-':
                    stack.push_back(left-right);
                    break;
                case '/':
                    if (right == 0)
                        throw std::runtime_error("Error");
                    stack.push_back(left/right);
                    break;
                case '*':
                    stack.push_back(left*right);
                    break;
            }
        }
    }
    if (stack.size() >= 2 || stack.empty())
        throw std::runtime_error("Error");
    std::cout << stack.back() << std::endl;
}