#include "Form.hpp"

Form::Form() : name("Default"), isSigned(false), signedGrade(150), executeGrade(150) {}

Form::Form(const std::string name, const int signedGrade, const int executeGrade): name(name), signedGrade(signedGrade), executeGrade(executeGrade) {
    isSigned = false;
    if (this->signedGrade < 1 || this->executeGrade < 1)
        throw GradeTooHighException();
    if (this->signedGrade > 150 || this->executeGrade > 150)
        throw GradeTooLowException();
}

Form& Form::operator=(const Form& other) {
    this->isSigned = other.isSigned;
    return *this;
}

Form::Form(const Form& other) : name(other.name), isSigned(other.isSigned), signedGrade(other.signedGrade), executeGrade(other.executeGrade) {}

Form::~Form() {}

std::string Form::getName() const {
    return this->name;
}

bool Form::getIsSigned() const {
    return this->isSigned;
}

int Form::getSignGrade() const {
    return this->signedGrade;
}

int Form::getExecuteGrade() const {
    return this->executeGrade;
}

void Form::beSigned(const Bureaucrat& bureaucrat) {
    if (bureaucrat.getGrade() <= this->signedGrade)
        this->isSigned = true;
    else 
        throw GradeTooLowException();
}

const char * Form::GradeTooHighException::what() const throw()
{
    return "Form grade is too high!";
}

const char * Form::GradeTooLowException::what() const throw()
{
    return "Form grade is too low!";
}

std::ostream& operator<<(std::ostream & os, const Form & form)
{
    os << form.getName() << ", Form grade required to sign: " << form.getSignGrade()
       << ", Form grade required to execute: " << form.getExecuteGrade()
       << ", Is signed: " << (form.getIsSigned() ? "Yes" : "No");
    return os;
}