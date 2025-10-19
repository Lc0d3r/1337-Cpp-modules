#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern() {};

Intern::Intern(const Intern& other) {
    (void)other;
} ;

Intern& Intern::operator=(const Intern& other) {
    (void)other;
    return *this;
} ;

Intern::~Intern() {};

AForm* Intern::makeForm(const std::string& formName, const std::string& target) {
    std::string formTypes[3] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };

    for (int i = 0; i < 3; ++i) {
        if (formName == formTypes[i]) {
            std::cout << "Intern creates " << formName << " form." << std::endl;
            switch (i) {
                case 0:
                    return new ShrubberyCreationForm(target);
                case 1:
                    return new RobotomyRequestForm(target);
                case 2:
                    return new PresidentialPardonForm(target);
            }
        }
    }

    std::cout << "Intern could not find the form: " << formName << std::endl;
    return NULL;
}
