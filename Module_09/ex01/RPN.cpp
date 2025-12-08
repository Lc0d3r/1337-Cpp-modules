#include "RPN.hpp"

void parse(char *str) {
    std::stringstream ss;

    ss << str;

    std::string input;
    ss >> input;
    int count =  0;
    if (input.empty()) 
        throw std::runtime_error("Error: the arg is empty!");
    while (!input.empty()) {
        count++;
        // std::cout << input << std::endl;
        if (input.size() > 1)
            throw std::runtime_error("Error!");
        if (!isdigit(input[0]) && input[0] != '+' && input[0] != '-' && input[0] != '*' && input[0] != '/')
            throw std::runtime_error("Error: one of the args is not digit!");
        input.clear();
        ss >> input;
    }
    if (count < 3)
        throw std::runtime_error("Error: number of args if not enough!");
}

void evaluateRPN(char *str) {
    std::list<int> stack;
    std::stringstream ss;

    ss << str;

    int number;
    std::string check;
    while (ss >> check) {
        if (isdigit(check[0])) {
            number = atoi(check.c_str());
            stack.push_back(number);
        }
        else {
            if (stack.size() < 2)   
                throw std::runtime_error("Error: operator without enough operand");
            int right = stack.back();
            stack.pop_back();
            int left = stack.back();
            stack.pop_back();
            switch (check[0]) {
                case '+':
                    stack.push_back(left+right);
                    break;
                case '-':
                    stack.push_back(left-right);
                    break;
                case '/':
                    if (right == 0)
                        throw std::runtime_error("Error: Division by zero.");
                    stack.push_back(left/right);
                    break;
                case '*':
                    stack.push_back(left*right);
                    break;
            }
        }
    }
    if (stack.size() >= 2)
        throw std::runtime_error("Error: the final result is more than one");
    std::cout << stack.back() << std::endl;
}