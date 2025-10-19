#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main() {
    std::cout << "=== Valid Form Creation ===" << std::endl;
    try {
        Bureaucrat hamoda("hamoda", 1);
        ShrubberyCreationForm passport("Passport");
        passport.beSigned(hamoda);
        passport.execute(hamoda);
        std::cout << hamoda << std::endl;
        std::cout << passport << std::endl;
    } catch (std::exception &e) {
        std::cout << "Exception during form creation: " << e.what() << std::endl;
    }

    return 0;
}
