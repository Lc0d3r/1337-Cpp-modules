#include <vector>
#include <iostream>
#include "easyfind.hpp"


int main() {
    std::vector<int> data;
    data.push_back(78);
    data.push_back(7);
    data.push_back(0);
    data.push_back(768);
    data.push_back(578);
    data.push_back(8);

    try {
        int result = easyfind<std::vector<int> >(data, 10);
        std::cout <<  "the element are found and it is " << result << std::endl;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
}