#include "AForm.hpp"

AForm::AForm() : name("Default"), isSigned(false), signedGrade(150), executeGrade(150) {}

AForm::AForm(const std::string name, const int signedGrade, const int executeGrade): name(name), signedGrade(signedGrade), executeGrade(executeGrade) {
    if (this->signedGrade < 1 || this->executeGrade < 1)
        throw GradeTooHighException();
    if (this->signedGrade > 150 || this->executeGrade > 150)
        throw GradeTooLowException();
}

AForm& AForm::operator=(const AForm& other) {
    this->isSigned = other.isSigned;
    return *this;
}

AForm::AForm(const AForm& other) : name(other.name), isSigned(other.isSigned), signedGrade(other.signedGrade), executeGrade(other.executeGrade) {}

AForm::~AForm() {}

std::string AForm::getName() const {
    return this->name;
}

bool AForm::getIsSigned() const {
    return this->isSigned;
}

int AForm::getSignGrade() const {
    return this->signedGrade;
}

int AForm::getExecuteGrade() const {
    return this->executeGrade;
}

void AForm::beSigned(const Bureaucrat& bureaucrat) {
    if (bureaucrat.getGrade() <= this->signedGrade)
        this->isSigned = true;
    else 
        throw GradeTooLowException();
}


std::ostream& operator<<(std::ostream & os, const AForm & AForm)
{
    os << AForm.getName() << ", AForm grade required to sign: " << AForm.getSignGrade()
    << ", AForm grade required to execute: " << AForm.getExecuteGrade()
    << ", Is signed: " << (AForm.getIsSigned() ? "Yes." : "No.");
    return os;
}

const char * AForm::GradeTooHighException::what() const throw()
{
    return "Form grade is too high!";
}

const char * AForm::GradeTooLowException::what() const throw()
{
    return "Form grade is too low!";
}

void AForm::execute(Bureaucrat const & executor) const {
    if (this->getIsSigned() == false)
        throw FormNotSignedException();
    if (executor.getGrade() > this->getExecuteGrade())
        throw GradeTooLowException();
    this->action();
}

const char *AForm::FormNotSignedException::what() const throw() {
    return "Form not signed";
}