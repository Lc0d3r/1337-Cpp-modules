#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include <iostream>

int main() {
    std::cout << "=== TEST 1: Subject Example ===" << std::endl;
    {
        Intern someRandomIntern;
        AForm* rrf;
        
        rrf = someRandomIntern.makeForm("robotomy request", "Bender");
        
        if (rrf) {
            Bureaucrat boss("Boss", 1);
            boss.signForm(*rrf);
            boss.executeForm(*rrf);
            delete rrf;
        }
    }
    
    std::cout << "\n=== TEST 2: All Three Form Types ===" << std::endl;
    {
        Intern intern;
        Bureaucrat ceo("CEO", 1);
        
        AForm* form1 = intern.makeForm("shrubbery creation", "home");
        AForm* form2 = intern.makeForm("robotomy request", "target");
        AForm* form3 = intern.makeForm("presidential pardon", "criminal");
        
        if (form1) {
            ceo.signForm(*form1);
            ceo.executeForm(*form1);
            delete form1;
        }
        
        if (form2) {
            ceo.signForm(*form2);
            ceo.executeForm(*form2);
            delete form2;
        }
        
        if (form3) {
            ceo.signForm(*form3);
            ceo.executeForm(*form3);
            delete form3;
        }
    }
    
    std::cout << "\n=== TEST 3: Invalid Form Names ===" << std::endl;
    {
        Intern intern;
        AForm* form;
        
        form = intern.makeForm("invalid form", "target");
        if (!form)
            std::cout << "Correctly returned NULL for invalid form\n" << std::endl;
        
        form = intern.makeForm("", "target");
        if (!form)
            std::cout << "Correctly returned NULL for empty form name\n" << std::endl;
        
        form = intern.makeForm("coffee maker", "office");
        if (!form)
            std::cout << "Correctly returned NULL for unknown form\n" << std::endl;
    }
    
    std::cout << "\n=== TEST 4: Grade Requirements ===" << std::endl;
    {
        Intern intern;
        Bureaucrat lowGrade("Junior", 100);
        Bureaucrat highGrade("Senior", 1);
        
        AForm* pardon = intern.makeForm("presidential pardon", "prisoner");
        
        if (pardon) {
            std::cout << *pardon << std::endl;
            
            lowGrade.signForm(*pardon);  // Should fail
            highGrade.signForm(*pardon); // Should succeed
            highGrade.executeForm(*pardon);
            
            delete pardon;
        }
    }
    
    std::cout << "\n=== All tests completed ===" << std::endl;
    
    return 0;
}