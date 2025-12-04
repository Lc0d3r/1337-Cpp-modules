#include "PmergeMe.hpp"

int main(int argc, char **argv) {
    if (argc == 1)
        return printErr("Error: Use the program like this => ./PmergeMe \"some ints\"");
    (void)argv;
    return 0;
}