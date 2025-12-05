#include "Bureaucrat.hpp"

#include "Form.hpp"
#include <iostream>

#define RED "\033[31m"
#define GREEN "\033[32m"
#define RESET "\033[0m"

Bureaucrat::Bureaucrat() :
    m_name("Default Bureaucrat"),
    m_grade(150)
{}

Bureaucrat::Bureaucrat(const std::string& name, int grade) :
    m_name(name),
    m_grade(grade)
{
    if (grade < 1) {
        throw GradeTooHighException();
    }
    if (grade > 150) {
        throw GradeTooLowException();
    }
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) :
    m_name(other.m_name),
    m_grade(other.m_grade)
{}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
    if (this != &other) {
        // m_name cannot be assigned because is const
        m_grade = other.m_grade;
    }
    return *this;
}

Bureaucrat::~Bureaucrat() {}


const std::string& Bureaucrat::getName() const { return m_name; }

int Bureaucrat::getGrade() const { return m_grade; }


void Bureaucrat::incrementGrade() {
    if (m_grade <= 1) {
        throw GradeTooHighException();
    }

    m_grade--;
}

void Bureaucrat::decrementGrade() {
    if (m_grade >= 150) {
        throw GradeTooLowException();
    }

    m_grade++;
}


const char* Bureaucrat::GradeTooHighException::what() const throw() { return "Bureaucrat grade too high!"; }

const char* Bureaucrat::GradeTooLowException::what() const throw() { return "Bureaucrat grade too low!"; }


void Bureaucrat::signForm(Form& form) const {
    try {
        form.beSigned(*this);
        std::cout << GREEN << m_name << " signed " << form.getName() << "." << RESET << "\n";
    } catch (const std::exception& e) {
        std::cerr << RED << m_name << " couldn't sign " << form.getName() << " because " << e.what() << RESET << "\n";
    }
}


std::ostream& operator<<(std::ostream& os, const Bureaucrat& b) {
    os << b.getName() << ", bureaucrat grade " << b.getGrade() << ".\n";
    return os;
}
