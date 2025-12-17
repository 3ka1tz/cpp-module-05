#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

#define RED "\033[31m"
#define BLUE "\033[34m"
#define RESET "\033[0m"

int main()
{
    std::cout << "\n" << BLUE << "Test 0: Default Form" << RESET << std::endl;
    try
    {
        Form fx;
        std::cout << fx;
    }
    catch (const std::exception& e)
    {
        std::cerr << RED << e.what() << RESET << std::endl;
    }

    std::cout << "\n" << BLUE << "Test 1: Valid Form" << RESET << std::endl;
    try
    {
        Form f1("Form1", 42, 42);
        std::cout << f1;
    }
    catch (const std::exception& e)
    {
        std::cerr << RED << e.what() << RESET << std::endl;
    }

    std::cout << "\n" << BLUE << "Test 2: Too High Grade Form" << RESET << std::endl;
    try
    {
        Form f2("Form2", 0, 0);
        std::cout << f2;
    }
    catch (const std::exception& e)
    {
        std::cerr << RED << e.what() << RESET << std::endl;
    }

    std::cout << "\n" << BLUE << "Test 3: Too Low Grade Form" << RESET << std::endl;
    try
    {
        Form f3("Form3", 151, 151);
        std::cout << f3;
    }
    catch (const std::exception& e)
    {
        std::cerr << RED << e.what() << RESET << std::endl;
    }

    std::cout << "\n" << BLUE << "Test 4: Sign Form" << RESET << std::endl;
    try
    {
        Bureaucrat a("Alice", 43);
        std::cout << a;
        Form f4("Form4", 42, 42);
        std::cout << f4;
        a.signForm(f4);

        std::cout << std::endl;

        a.incrementGrade();
        std::cout << a;
        std::cout << f4;
        a.signForm(f4);

        std::cout << std::endl;

        std::cout << f4;
    }
    catch (const std::exception& e)
    {
        std::cerr << RED << e.what() << RESET << std::endl;
    }

    std::cout << std::endl;
}
