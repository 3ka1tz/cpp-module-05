#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

#define RED "\033[31m"
#define GREEN "\033[32m"
#define RESET "\033[0m"

// -------------------------------------------------------------------------------------------------
// Orthodox Canonical Class Form

Bureaucrat::Bureaucrat() : name("Default"), grade(150) {}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : name(name), grade(grade)
{
    if (grade < 1)
    {
        throw GradeTooHighException();
    }
    else if (grade > 150)
    {
        throw GradeTooLowException();
    }
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : name(other.name), grade(other.grade) {}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
    if (this != &other)
    {
        // 'name' is a const member, so it cannot be reassigned
        grade = other.grade;
    }
    return *this;
}

Bureaucrat::~Bureaucrat() {}


// -------------------------------------------------------------------------------------------------
// Getters

const std::string& Bureaucrat::getName() const { return name; }

int Bureaucrat::getGrade() const { return grade; }


// -------------------------------------------------------------------------------------------------
// Grade incrementor and decrementor functions

void Bureaucrat::incrementGrade()
{
    if (grade <= 1)
    {
        throw GradeTooHighException();
    }

    grade--;
}

void Bureaucrat::decrementGrade()
{
    if (grade >= 150)
    {
        throw GradeTooLowException();
    }

    grade++;
}


// -------------------------------------------------------------------------------------------------
// Bureaucrat grade outside of bounds exceptions

const char* Bureaucrat::GradeTooHighException::what() const throw() { return "Bureaucrat grade is too high!"; }

const char* Bureaucrat::GradeTooLowException::what() const throw() { return "Bureaucrat grade is too low!"; }


// -------------------------------------------------------------------------------------------------
// Sign Form

void Bureaucrat::signForm(Form& form) const
{
    try
    {
        form.beSigned(*this);
        std::cout << GREEN << name << " signed " << form.getName() << "." << RESET << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << RED << name << " couldn't sign " << form.getName() << " because " << e.what() << RESET << std::endl;
    }
}


// -------------------------------------------------------------------------------------------------
// Overload of the insertion operator

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b)
{
    os << b.getName() << ", bureaucrat grade " << b.getGrade() << "." << std::endl;
    return os;
}
