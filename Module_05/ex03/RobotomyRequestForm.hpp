#pragma once

#include "AForm.hpp"
#include <string>

class RobotomyRequestForm: public AForm {
    private:
        std::string target;
    public:
        RobotomyRequestForm();
        RobotomyRequestForm(std::string _target);
        RobotomyRequestForm(const RobotomyRequestForm& other);
        RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
        ~RobotomyRequestForm();

        void action() const;
};
