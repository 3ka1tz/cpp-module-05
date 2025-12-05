#include "Bureaucrat.hpp"
#include "Form.hpp"

#include <iostream>

#define RED "\033[31m"
#define BLUE "\033[34m"
#define RESET "\033[0m"

int main() {
    std::cout << "\n" << BLUE << "Test 1: Form Grade" << RESET << "\n";
    try {
        Form sampleForm("Sample Form", 0, 151);
        std::cout << sampleForm;
    } catch (const std::exception& e) {
        std::cerr << RED << e.what() << RESET << "\n";
    }

    std::cout << "\n" << BLUE << "Test 2: Sign Form" << RESET << "\n";
    try {
        Bureaucrat alice("Alice", 42);
        std::cout << alice;
        Form sampleForm("Sample Form", 41, 82);
        std::cout << sampleForm;
        alice.signForm(sampleForm);
        std::cout << "\n";

        alice.incrementGrade();
        std::cout << alice;
        std::cout << sampleForm;
        alice.signForm(sampleForm);
        std::cout << "\n";

        std::cout << sampleForm;
    } catch (const std::exception& e) {
        std::cerr << RED << e.what() << RESET << "\n";
    }

    std::cout << "\n";
}
