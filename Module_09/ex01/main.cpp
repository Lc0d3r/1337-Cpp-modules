#include "RPN.hpp"

int main(int argc, char **argv) {
    try {
        (void)argv;
        if (argc < 2)
            throw std::runtime_error("Error: number of args is not enough!");
        evaluateRPN(argv[1]);
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }
    return 0;
}