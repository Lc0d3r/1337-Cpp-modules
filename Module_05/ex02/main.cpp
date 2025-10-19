#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

void printSeparator(const std::string& title) {
    std::cout << "\n========== " << title << " ==========\n" << std::endl;
}

void testShrubberyCreation() {
    printSeparator("SHRUBBERY CREATION FORM TESTS");
    
    try {
        Bureaucrat lowGrade("LowGrade", 150);
        Bureaucrat midGrade("MidGrade", 140);
        Bureaucrat highGrade("HighGrade", 1);
        ShrubberyCreationForm form("garden");
        
        std::cout << form << std::endl;
        
        // Test: Try to execute unsigned form
        std::cout << "\n--- Test: Execute unsigned form ---" << std::endl;
        try {
            highGrade.executeForm(form);
        } catch (std::exception& e) {
            std::cout << "Exception: " << e.what() << std::endl;
        }
        
        // Test: Try to sign with too low grade
        std::cout << "\n--- Test: Sign with too low grade (150) ---" << std::endl;
        lowGrade.signForm(form);
        
        // Test: Sign with sufficient grade
        std::cout << "\n--- Test: Sign with sufficient grade (140) ---" << std::endl;
        midGrade.signForm(form);
        
        // Test: Execute with too low grade
        std::cout << "\n--- Test: Execute with too low grade (140) ---" << std::endl;
        midGrade.executeForm(form);
        
        // Test: Execute with sufficient grade
        std::cout << "\n--- Test: Execute with sufficient grade (1) ---" << std::endl;
        highGrade.executeForm(form);
        std::cout << "Check for 'garden_shrubbery' file in current directory!" << std::endl;
        
    } catch (std::exception& e) {
        std::cout << "Unexpected exception: " << e.what() << std::endl;
    }
}

void testRobotomyRequest() {
    printSeparator("ROBOTOMY REQUEST FORM TESTS");
    
    try {
        Bureaucrat lowGrade("LowBureaucrat", 100);
        Bureaucrat midGrade("MidBureaucrat", 50);
        Bureaucrat highGrade("HighBureaucrat", 1);
        RobotomyRequestForm form("Bender");
        
        std::cout << form << std::endl;
        
        // Test: Try to sign with too low grade
        std::cout << "\n--- Test: Sign with too low grade (100) ---" << std::endl;
        lowGrade.signForm(form);
        
        // Test: Sign with sufficient grade
        std::cout << "\n--- Test: Sign with sufficient grade (50) ---" << std::endl;
        midGrade.signForm(form);
        
        // Test: Execute with too low grade
        std::cout << "\n--- Test: Execute with too low grade (50) ---" << std::endl;
        midGrade.executeForm(form);
        
        // Test: Execute multiple times to see randomness (50% success rate)
        std::cout << "\n--- Test: Execute 5 times to see randomness ---" << std::endl;
        for (int i = 0; i < 5; i++) {
            std::cout << "Attempt " << (i + 1) << ": ";
            highGrade.executeForm(form);
        }
        
    } catch (std::exception& e) {
        std::cout << "Unexpected exception: " << e.what() << std::endl;
    }
}

void testPresidentialPardon() {
    printSeparator("PRESIDENTIAL PARDON FORM TESTS");
    
    try {
        Bureaucrat lowGrade("Junior", 50);
        Bureaucrat midGrade("Senior", 20);
        Bureaucrat highGrade("Director", 1);
        PresidentialPardonForm form("Arthur Dent");
        
        std::cout << form << std::endl;
        
        // Test: Try to sign with too low grade
        std::cout << "\n--- Test: Sign with too low grade (50) ---" << std::endl;
        lowGrade.signForm(form);
        
        // Test: Sign with sufficient grade
        std::cout << "\n--- Test: Sign with sufficient grade (20) ---" << std::endl;
        midGrade.signForm(form);
        
        // Test: Execute with too low grade
        std::cout << "\n--- Test: Execute with too low grade (20) ---" << std::endl;
        midGrade.executeForm(form);
        
        // Test: Execute with sufficient grade
        std::cout << "\n--- Test: Execute with sufficient grade (1) ---" << std::endl;
        highGrade.executeForm(form);
        
    } catch (std::exception& e) {
        std::cout << "Unexpected exception: " << e.what() << std::endl;
    }
}

void testAllFormsComparison() {
    printSeparator("ALL FORMS COMPARISON");
    
    try {
        Bureaucrat god("God", 1);
        
        ShrubberyCreationForm shrubbery("home");
        RobotomyRequestForm robotomy("Employee");
        PresidentialPardonForm pardon("Criminal");
        
        std::cout << shrubbery << std::endl;
        std::cout << robotomy << std::endl;
        std::cout << pardon << std::endl;
        
        std::cout << "\n--- Signing all forms with grade 1 bureaucrat ---" << std::endl;
        god.signForm(shrubbery);
        god.signForm(robotomy);
        god.signForm(pardon);
        
        std::cout << "\n--- Executing all forms ---" << std::endl;
        god.executeForm(shrubbery);
        god.executeForm(robotomy);
        god.executeForm(pardon);
        
    } catch (std::exception& e) {
        std::cout << "Unexpected exception: " << e.what() << std::endl;
    }
}

void testEdgeCases() {
    printSeparator("EDGE CASES");
    
    try {
        // Test: Bureaucrat with exact required grade for signing
        std::cout << "--- Test: Exact grade for signing Shrubbery (145) ---" << std::endl;
        Bureaucrat exact("Exact", 145);
        ShrubberyCreationForm form("test");
        exact.signForm(form);
        std::cout << form << std::endl;
        
        // Test: Bureaucrat with exact required grade for execution
        std::cout << "\n--- Test: Exact grade for executing Shrubbery (137) ---" << std::endl;
        Bureaucrat exactExec("ExactExec", 137);
        exactExec.executeForm(form);
        
        // Test: Try to sign already signed form
        std::cout << "\n--- Test: Sign already signed form ---" << std::endl;
        exact.signForm(form);
        
    } catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
}

int main() {
    std::cout << "╔════════════════════════════════════════════╗" << std::endl;
    std::cout << "║   C++ MODULE 05 - EXERCISE 02 TEST SUITE  ║" << std::endl;
    std::cout << "╚════════════════════════════════════════════╝" << std::endl;
    
    testShrubberyCreation();
    testRobotomyRequest();
    testPresidentialPardon();
    testAllFormsComparison();
    testEdgeCases();
    
    printSeparator("ALL TESTS COMPLETED");
    
    return 0;
}