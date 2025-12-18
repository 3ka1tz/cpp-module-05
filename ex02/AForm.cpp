#include "AForm.hpp"
#include "Bureaucrat.hpp"

// -------------------------------------------------------------------------------------------------
// Orthodox Canonical Class Form

AForm::AForm() :
    name("Default AForm"),
    isSigned(false),
    gradeToSign(150),
    gradeToExecute(150)
{}

AForm::AForm(const std::string& name, const int gradeToSign, const int gradeToExecute) :
    name(name),
    isSigned(false),
    gradeToSign(gradeToSign),
    gradeToExecute(gradeToExecute)
{
    if (gradeToSign < 1 || gradeToExecute < 1)
    {
        throw GradeTooHighException();
    }
    else if (gradeToSign > 150 || gradeToExecute > 150)
    {
        throw GradeTooLowException();
    }
}

AForm::AForm(const AForm& other) :
    name(other.name),
    isSigned(other.isSigned),
    gradeToSign(other.gradeToSign),
    gradeToExecute(other.gradeToExecute)
{}

AForm& AForm::operator=(const AForm& other)
{
    if (this != &other)
    {
        // 'name', 'gradeToSign' and 'gradeToExecute' are const members, so they cannot be reassigned
        isSigned = other.isSigned;
    }
    return *this;
}

AForm::~AForm() {}


// -------------------------------------------------------------------------------------------------
// Getters

const std::string& AForm::getName() const { return name; }

bool AForm::getIsSigned() const { return isSigned; }

int AForm::getGradeToSign() const { return gradeToSign; }

int AForm::getGradeToExecute() const { return gradeToExecute; }


// -------------------------------------------------------------------------------------------------
// Exceptions

const char* AForm::GradeTooHighException::what() const throw() { return "AForm grade is too high!"; }

const char* AForm::GradeTooLowException::what() const throw() { return "AForm grade is too low!"; }

const char* AForm::FormNotSignedException::what() const throw() { return "Form must be signed before executing it!"; }


// -------------------------------------------------------------------------------------------------
// Be signed and be executed functions

void AForm::beSigned(const Bureaucrat& bureaucrat)
{
    if (bureaucrat.getGrade() > gradeToSign)
    {
        throw Bureaucrat::GradeTooLowException();
    }

    isSigned = true;
}

void AForm::beExecuted(const Bureaucrat& bureaucrat) const {
    if (!isSigned)
    {
        throw FormNotSignedException();
    }

    if (bureaucrat.getGrade() > gradeToExecute)
    {
        throw Bureaucrat::GradeTooLowException();
    }

    executeAction();
}


// -------------------------------------------------------------------------------------------------
// Overload of the insertion operator

std::ostream& operator<<(std::ostream& os, const AForm& f)
{
    os << f.getName() << ": isSigned = " << (f.getIsSigned() ? "yes" : "no") << ", gradeToSign = " << f.getGradeToSign() << ", gradeToExecute = " << f.getGradeToExecute() << ";" << std::endl;
    return os;
}
