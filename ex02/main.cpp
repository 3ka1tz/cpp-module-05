#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

#include <cstdlib>
#include <ctime>
#include <iostream>

#define RED "\033[31m"
#define BLUE "\033[34m"
#define RESET "\033[0m"

int main() {
    srand(time(NULL));

    std::cout << "\n" << BLUE << "Test 1: Presidential Pardon Form" << RESET << "\n";
    try {
        Bureaucrat alice("Alice", 5);
        std::cout << alice;
        PresidentialPardonForm PPForm("Amy");
        std::cout << PPForm;
        alice.signForm(PPForm);
        std::cout << PPForm;
        alice.executeForm(PPForm);
    } catch (const std::exception& e) {
        std::cerr << RED << e.what() << RESET << "\n";
    }

    std::cout << "\n" << BLUE << "Test 2: Robotomy Request Form" << RESET << "\n";
    try {
        Bureaucrat bob("Bob", 45);
        std::cout << bob;
        RobotomyRequestForm RRForm("Barry");
        std::cout << RRForm;
        bob.signForm(RRForm);
        std::cout << RRForm;
        bob.executeForm(RRForm);
    } catch (const std::exception& e) {
        std::cerr << RED << e.what() << RESET << "\n";
    }

    std::cout << "\n" << BLUE << "Test 3: Shrubbery Creation Form" << RESET << "\n";
    try {
        Bureaucrat charlie("Charlie", 137);
        std::cout << charlie;
        ShrubberyCreationForm SCForm("home");
        std::cout << SCForm;
        charlie.signForm(SCForm);
        std::cout << SCForm;
        charlie.executeForm(SCForm);
    } catch (const std::exception& e) {
        std::cerr << RED << e.what() << RESET << "\n";
    }

    std::cout << "\n";
}
