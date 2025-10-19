#include "Bureaucrat.hpp"
#include "AForm.hpp"

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

void Bureaucrat::executeForm(AForm const & form) {
    if (this->getGrade() <= form.getExecuteGrade() && form.getIsSigned())
        try {
            form.execute(*this);
            std::cout << this->getName() << " executed " << form.getName() << std::endl;
        } catch (std::exception& e) {
            std::cout << this->getName() << " couldn't execute " << form.getName() << " because " << e.what() << "." << std::endl;
            return;
        }
    else 
        std::cout << this->getName() << " can't execute " << form.getName() << std::endl;
}

void Bureaucrat::signForm(AForm &form) {
    try {
        form.beSigned(*this);
        std::cout << this->getName() << " signed " << form.getName() << std::endl;
    }catch (std::exception& e) {
        std::cout << this->getName() << " couldn’t sign " << form.getName() << " because " << e.what() << "." << std::endl;
    }
}