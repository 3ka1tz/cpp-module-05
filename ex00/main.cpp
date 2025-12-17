#include "Bureaucrat.hpp"

#include <iostream>

#define RED "\033[31m"
#define BLUE "\033[34m"
#define RESET "\033[0m"

int main()
{
    std::cout << "\n" << BLUE << "Test 1: Valid Grade" << RESET << std::endl;
    try
    {
        Bureaucrat a("Alice", 42);
        std::cout << a;
    }
    catch (const std::exception& e)
    {
        std::cerr << RED << e.what() << RESET << std::endl;
    }

    std::cout << "\n" << BLUE << "Test 2: Invalid Too High Grade" << RESET << std::endl;
    try
    {
        Bureaucrat b("Bob", 0);
        std::cout << b;
    }
    catch (const std::exception& e)
    {
        std::cerr << RED << e.what() << RESET << std::endl;
    }

    std::cout << "\n" << BLUE << "Test 3: Invalid Too Low Grade" << RESET << std::endl;
    try
    {
        Bureaucrat c("eve", 151);
        std::cout << c;
    }
    catch (const std::exception& e)
    {
        std::cerr << RED << e.what() << RESET << std::endl;
    }

    std::cout << "\n" << BLUE << "Test 4: Increment Grade" << RESET << std::endl;
    try
    {
        Bureaucrat d("Dave", 2);
        std::cout << d;
        d.incrementGrade();
        std::cout << d;
        d.incrementGrade();
        std::cout << d;
    }
    catch (const std::exception& e)
    {
        std::cerr << RED << e.what() << RESET << "\n";
    }

    std::cout << "\n" << BLUE << "Test 5: Decrement Grade" << RESET << std::endl;
    try
    {
        Bureaucrat eve("Eve", 149);
        std::cout << eve;
        eve.decrementGrade();
        std::cout << eve;
        eve.decrementGrade();
        std::cout << eve;
    }
    catch (const std::exception& e)
    {
        std::cerr << RED << e.what() << RESET << "\n";
    }

    std::cout << std::endl;
}
