#pragma once

#include "AForm.hpp"
#include <string>

class PresidentialPardonForm: public AForm {
    private:
        std::string target;
    public:
        PresidentialPardonForm();
        PresidentialPardonForm(std::string _target);
        PresidentialPardonForm(const PresidentialPardonForm& other);
        PresidentialPardonForm& operator=(const PresidentialPardonForm& other);
        ~PresidentialPardonForm();

        void action() const;
};
