#pragma once 


#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"


class AForm {
    const std::string name;
    bool isSigned;
    const int signedGrade;
    const int executeGrade;
public:
    AForm();
    AForm(const std::string name, const int signedGrade, const int executeGrade);
    AForm& operator=(const AForm& other);
    AForm(const AForm& other);
    virtual ~AForm();
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

    class FormNotSignedException : public std::exception 
    {
        public:
            const char *what() const throw();
    };
    
    void execute(Bureaucrat const & executor) const ;
    virtual void action() const = 0;
};

std::ostream &operator<<(std::ostream &out,  AForm const &AForm);