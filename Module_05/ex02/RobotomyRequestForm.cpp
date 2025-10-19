#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), target("default") {}


RobotomyRequestForm::RobotomyRequestForm(std::string _target) : AForm("RobotomyRequestForm",72, 45), target(_target) {};

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm(other), target(other.target) {};

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
    if (this != &other)
    {
        target = other.target;
        AForm::operator=(other);
    }
    return *this;
};

RobotomyRequestForm::~RobotomyRequestForm() {};

static int robot_fail = 0;

void RobotomyRequestForm::action() const {
    if (robot_fail++ % 2)
        std::cout << "* Bzzzz... * " << target << " has been robotomized successfully!" << std::endl;
    else 
        std::cout << "Robotomy failed on " << target << std::endl; 
}