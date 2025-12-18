#include "Form.hpp"
#include "Bureaucrat.hpp"

// -------------------------------------------------------------------------------------------------
// Orthodox Canonical Class Form

Form::Form() :
    name("Default Form"),
    isSigned(false),
    gradeToSign(150),
    gradeToExecute(150)
{}

Form::Form(const std::string& name, const int gradeToSign, const int gradeToExecute) :
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

Form::Form(const Form& other) :
    name(other.name),
    isSigned(other.isSigned),
    gradeToSign(other.gradeToSign),
    gradeToExecute(other.gradeToExecute)
{}

Form& Form::operator=(const Form& other)
{
    if (this != &other)
    {
        // 'name', 'gradeToSign' and 'gradeToExecute' are const members, so they cannot be reassigned
        isSigned = other.isSigned;
    }
    return *this;
}

Form::~Form() {}


// -------------------------------------------------------------------------------------------------
// Getters

const std::string& Form::getName() const { return name; }

bool Form::getIsSigned() const { return isSigned; }

int Form::getGradeToSign() const { return gradeToSign; }

int Form::getGradeToExecute() const { return gradeToExecute; }


// -------------------------------------------------------------------------------------------------
// Form grade outside of bounds exceptions

const char* Form::GradeTooHighException::what() const throw() { return "Form grade is too high!"; }

const char* Form::GradeTooLowException::what() const throw() { return "Form grade is too low!"; }


// -------------------------------------------------------------------------------------------------
// Be Signed

void Form::beSigned(const Bureaucrat& bureaucrat)
{
    if (bureaucrat.getGrade() > gradeToSign)
    {
        throw Bureaucrat::GradeTooLowException();
    }

    isSigned = true;
}


// -------------------------------------------------------------------------------------------------
// Overload of the insertion operator

std::ostream& operator<<(std::ostream& os, const Form& f)
{
    os << f.getName() << ": isSigned = " << (f.getIsSigned() ? "yes" : "no") << ", gradeToSign = " << f.getGradeToSign() << ", gradeToExecute = " << f.getGradeToExecute() << ";" << std::endl;
    return os;
}
