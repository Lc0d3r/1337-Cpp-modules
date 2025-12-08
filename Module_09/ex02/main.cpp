#include "PmergeMe.hpp"

int main(int argc, char **argv) {
    try {
        errorCheck(argc, argv);
        double time_mc_vc = sort_vect<std::vector<int> >(argc, argv, 1);
        double time_mc_dq = sort_vect<std::deque<int> >(argc, argv, 0);
        std::cout << "Time to process a range of " << argc - 1 << " elements with " << "an std::vector : " << time_mc_vc << " µs" <<std::endl;
        std::cout << "Time to process a range of " << argc - 1 << " elements with " << "an std::deque  : " << time_mc_dq << " µs" <<std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }
    return 0;
}