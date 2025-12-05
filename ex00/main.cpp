#include "Bureaucrat.hpp"

#include <iostream>

#define RED "\033[31m"
#define BLUE "\033[34m"
#define RESET "\033[0m"

int main() {
    std::cout << "\n" << BLUE << "Test 1: Grade" << RESET << "\n";
    try {
        Bureaucrat alice("Alice", 42);
        std::cout << alice;
    } catch (const std::exception& e) {
        std::cerr << RED << e.what() << RESET << "\n";
    }

    std::cout << "\n" << BLUE << "Test 2: Increment Grade" << RESET << "\n";
    try {
        Bureaucrat bob("Bob", 2);
        std::cout << bob;
        bob.incrementGrade();
        std::cout << bob;
        bob.incrementGrade();
        std::cout << bob;
    } catch (const std::exception& e) {
        std::cerr << RED << e.what() << RESET << "\n";
    }

    std::cout << "\n" << BLUE << "Test 3: Decrement Grade" << RESET << "\n";
    try {
        Bureaucrat charlie("Charlie", 149);
        std::cout << charlie;
        charlie.decrementGrade();
        std::cout << charlie;
        charlie.decrementGrade();
        std::cout << charlie;
    } catch (const std::exception& e) {
        std::cerr << RED << e.what() << RESET << "\n";
    }

    std::cout << "\n";
}
