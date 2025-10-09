#include "Bureaucrat.hpp"

int main() {
    std::cout << "=== Valid Bureaucrat ===" << std::endl;
    try {
        Bureaucrat b("Alice", 42);
        std::cout << b << std::endl;

        std::cout << "Incrementing grade..." << std::endl;
        b.incrementGrade();
        std::cout << b << std::endl;

        std::cout << "Decrementing grade..." << std::endl;
        b.decrementGrade();
        std::cout << b << std::endl;
    } catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Grade Too Low at Creation ===" << std::endl;
    try {
        Bureaucrat c("Bob", 151);
        std::cout << c << std::endl;
    } catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Grade Too High at Creation ===" << std::endl;
    try {
        Bureaucrat d("Charlie", 0);
        std::cout << d << std::endl;
    } catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Increment past upper limit ===" << std::endl;
    try {
        Bureaucrat e("Daisy", 1);
        std::cout << e << std::endl;
        e.incrementGrade(); // should throw
    } catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Decrement past lower limit ===" << std::endl;
    try {
        Bureaucrat f("Edward", 150);
        std::cout << f << std::endl;
        f.decrementGrade(); // should throw
    } catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
