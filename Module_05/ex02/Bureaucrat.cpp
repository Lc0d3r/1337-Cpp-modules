#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("Default"), grade(150) {};

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name) {
    if (grade > 150)
        throw GradeTooLowException();
    if (grade < 1)
        throw GradeTooHighException();
    this->grade = grade;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat& other) {
    if (this == &other)
        return *this;
    this->grade = other.grade;
    return *this;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other): name(other.name), grade(other.grade) {}

Bureaucrat::~Bureaucrat() {};

std::string Bureaucrat::getName() const {
    return name;
}

int Bureaucrat::getGrade() const {
    return grade;
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
    return "The grade is too high.";
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
    return "The grade is too low.";
}

void Bureaucrat::incrementGrade() {
    grade--;
    if (grade < 1)
        throw GradeTooHighException();
}

void Bureaucrat::decrementGrade() {
    grade++;
    if (grade > 150) 
        throw GradeTooLowException();
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& b) {
    out << b.getName() << ", bureaucrat grade " 
    << b.getGrade() << ".";
    return out;
}