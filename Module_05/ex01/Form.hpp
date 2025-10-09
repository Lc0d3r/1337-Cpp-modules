#pragma once 


#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"


class Form {
    const std::string name;
    bool isSigned;
    const int signedGrade;
    const int executeGrade;
public:
    Form();
    Form(const std::string name, const int signedGrade, const int executeGrade);
    Form& operator=(const Form& other);
    Form(const Form& other);
    ~Form();
    std::string getName() const;
    bool getIsSigned() const;
    int getSignGrade() const;
    int getExecuteGrade() const;
    void beSigned(const Bureaucrat &bureaucrat);

    class GradeTooHighException : public std::exception
    {
        public:
           const char *what() const throw();
    };
    
    class GradeTooLowException : public std::exception
    {
        public:
            const char *what() const throw();
    };
};

std::ostream &operator<<(std::ostream &out,  Form const &form);