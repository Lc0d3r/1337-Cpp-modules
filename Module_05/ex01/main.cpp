#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    std::cout << "=== Valid Form Creation ===" << std::endl;
    try {
        Form passport("Passport", 50, 25);
        std::cout << passport << std::endl;
    } catch (std::exception &e) {
        std::cout << "Exception during form creation: " << e.what() << std::endl;
    }

    std::cout << "\n=== Invalid Form Creation (Too High) ===" << std::endl;
    try {
        Form impossible("Impossible", 0, 25);
        std::cout << impossible << std::endl;
    } catch (std::exception &e) {
        std::cout << "Exception during form creation: " << e.what() << std::endl;
    }

    std::cout << "\n=== Invalid Form Creation (Too Low) ===" << std::endl;
    try {
        Form lazy("Lazy", 120, 151);
        std::cout << lazy << std::endl;
    } catch (std::exception &e) {
        std::cout << "Exception during form creation: " << e.what() << std::endl;
    }

    std::cout << "\n=== Bureaucrat Signing Tests ===" << std::endl;
    try {
        Bureaucrat alice("Alice", 30);
        Bureaucrat bob("Bob", 100);
        Form tax("Tax Form", 50, 70);

        std::cout << tax << std::endl;

        std::cout << "\n-- Bob tries to sign --" << std::endl;
        try {
            tax.beSigned(bob);
            std::cout << "Bob signed the form successfully." << std::endl;
        } catch (std::exception &e) {
            std::cout << "Bob failed to sign: " << e.what() << std::endl;
        }

        std::cout << "\n-- Alice tries to sign --" << std::endl;
        try {
            tax.beSigned(alice);
            std::cout << "Alice signed the form successfully." << std::endl;
        } catch (std::exception &e) {
            std::cout << "Alice failed to sign: " << e.what() << std::endl;
        }

        std::cout << "\nFinal Form Status:" << std::endl;
        std::cout << tax << std::endl;

    } catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
