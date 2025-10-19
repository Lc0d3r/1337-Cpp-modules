#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

int main() {
    std::cout << "=== Valid Form Creation ===" << std::endl;
    try {
        Bureaucrat hamoda("hamoda", 40);
        RobotomyRequestForm passport("Passport");
        passport.beSigned(hamoda);
        passport.execute(hamoda);
        passport.execute(hamoda);
        passport.execute(hamoda);
        passport.execute(hamoda);
        passport.execute(hamoda);
        passport.execute(hamoda);
        passport.execute(hamoda);
        std::cout << hamoda << std::endl;
        std::cout << passport << std::endl;
    } catch (std::exception &e) {
        std::cout << "Exception : " << e.what() << std::endl;
    }

    return 0;
}
