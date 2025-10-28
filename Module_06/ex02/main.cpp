#include "utils.hpp"

int main(void) {
    srand(time(NULL));

    for (int i = 0; i < 4; ++i) {
        Base* obj = generate();

        std::cout << "Identifying by pointer: ";
        identify(obj);

        std::cout << "Identifying by reference: ";
        identify(*obj);

        delete obj;
    }

    return 0;
}