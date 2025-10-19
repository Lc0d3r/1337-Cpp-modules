#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5), target("default") {}


PresidentialPardonForm::PresidentialPardonForm(std::string _target) : AForm("PresidentialPardonForm",25, 5), target(_target) {};

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) : AForm(other), target(other.target) {};

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other) {
    if (this != &other)
    {
        target = other.target;
        AForm::operator=(other);
    }
    return *this;
};

PresidentialPardonForm::~PresidentialPardonForm() {};

void PresidentialPardonForm::action() const {
    std::cout << target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}