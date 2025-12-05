#include "Bureaucrat.hpp"
#include "Intern.hpp"
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
        Bureaucrat alice("Alice", 1);
        Intern someRandomIntern1;
        AForm* ppf = someRandomIntern1.makeForm("presidential pardon", "Bender");
        std::cout << *ppf;
        alice.signForm(*ppf);
        std::cout << *ppf;
        alice.executeForm(*ppf);
    } catch (const std::exception& e) {
        std::cerr << RED << e.what() << RESET << "\n";
    }

    std::cout << "\n" << BLUE << "Test 2: Robotomy Request Form" << RESET << "\n";
    try {
        Bureaucrat bob("Bob", 1);
        Intern someRandomIntern2;
        AForm* rrf = someRandomIntern2.makeForm("robotomy request", "Carl");
        std::cout << *rrf;
        bob.signForm(*rrf);
        std::cout << *rrf;
        bob.executeForm(*rrf);
    } catch (const std::exception& e) {
        std::cerr << RED << e.what() << RESET << "\n";
    }

    std::cout << "\n" << BLUE << "Test 3: Shrubbery Creation Form" << RESET << "\n";
    try {
        Bureaucrat charlie("Charlie", 1);
        Intern someRandomIntern3;
        AForm* scf = someRandomIntern3.makeForm("shrubbery creation", "garden");
        std::cout << *scf;
        charlie.signForm(*scf);
        std::cout << *scf;
        charlie.executeForm(*scf);
    } catch (const std::exception& e) {
        std::cerr << RED << e.what() << RESET << "\n";
    }

    std::cout << "\n" << BLUE << "Test 4: Not Existing Form" << RESET << "\n";
    try {
        Bureaucrat dave("Dave", 1);
        Intern someRandomIntern4;
        AForm* rsf = someRandomIntern4.makeForm("random sample", "Elm");
        std::cout << *rsf;
        dave.signForm(*rsf);
        std::cout << *rsf;
        dave.executeForm(*rsf);
    } catch (const std::exception& e) {
        std::cerr << RED << e.what() << RESET << "\n";
    }

    std::cout << "\n";
}
