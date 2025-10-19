#pragma once

#include <iostream>
#include <exception>

class Bureaucrat {
    const std::string name;
    int grade;
public:
    Bureaucrat();
    Bureaucrat(std::string name, int grade);
    Bureaucrat &operator=(const Bureaucrat& other);
    Bureaucrat(const Bureaucrat& other);
    ~Bureaucrat();
    std::string getName() const ;
    int getGrade() const ;
    void incrementGrade();
    void decrementGrade();

    class GradeTooLowException : public std::exception {
    public:
        const char *what()const throw();
    };

    class GradeTooHighException : public std::exception {
    public:
        const char *what() const throw();
    };
    void signForm(Form &form);
};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& b);
