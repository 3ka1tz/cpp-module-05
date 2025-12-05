#include "Form.hpp"

#include "Bureaucrat.hpp"

Form::Form() :
    m_name("Default Form"),
    m_isSigned(false),
    m_gradeToSign(150),
    m_gradeToExecute(150)
{}

Form::Form(const std::string& name, const int gradeToSign, const int gradeToExecute) :
    m_name(name),
    m_isSigned(false),
    m_gradeToSign(gradeToSign),
    m_gradeToExecute(gradeToExecute)
{
    if (gradeToSign < 1 || gradeToExecute < 1) {
        throw GradeTooHighException();
    }
    if (gradeToSign > 150 || gradeToExecute > 150) {
        throw GradeTooLowException();
    }
}

Form::Form(const Form& other) :
    m_name(other.m_name),
    m_isSigned(other.m_isSigned),
    m_gradeToSign(other.m_gradeToSign),
    m_gradeToExecute(other.m_gradeToExecute)
{}

Form& Form::operator=(const Form& other) {
    if (this != &other) {
        // m_name, m_gradeToSign, m_gradeToExecute cannot be assigned because are const
        m_isSigned = other.m_isSigned;
    }
    return *this;
}

Form::~Form() {}


const std::string& Form::getName() const { return m_name; }

bool Form::getIsSigned() const { return m_isSigned; }

int Form::getGradeToSign() const { return m_gradeToSign; }

int Form::getGradeToExecute() const { return m_gradeToExecute; }


const char* Form::GradeTooHighException::what() const throw() { return "Form grade too high!"; }

const char* Form::GradeTooLowException::what() const throw() { return "Form grade too low!"; }


void Form::beSigned(const Bureaucrat& bureaucrat) {
    if (bureaucrat.getGrade() > m_gradeToSign) {
        throw Bureaucrat::GradeTooLowException();
    }

    m_isSigned = true;
}


std::ostream& operator<<(std::ostream& os, const Form& f) {
    os << f.getName() << ": isSigned = " << (f.getIsSigned() ? "yes" : "no") << ", gradeToSign = " << f.getGradeToSign() << ", gradeToExecute = " << f.getGradeToExecute() << ".\n";
    return os;
}
