#include "AForm.hpp"

#include "Bureaucrat.hpp"

AForm::AForm() :
    m_name("Default Form"),
    m_isSigned(false),
    m_gradeToSign(150),
    m_gradeToExecute(150)
{}

AForm::AForm(const std::string& name, const int gradeToSign, const int gradeToExecute) :
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

AForm::AForm(const AForm& other) :
    m_name(other.m_name),
    m_isSigned(other.m_isSigned),
    m_gradeToSign(other.m_gradeToSign),
    m_gradeToExecute(other.m_gradeToExecute)
{}

AForm& AForm::operator=(const AForm& other) {
    if (this != &other) {
        // m_name, m_gradeToSign, m_gradeToExecute cannot be assigned because are const
        m_isSigned = other.m_isSigned;
    }
    return *this;
}

AForm::~AForm() {}


const std::string& AForm::getName() const { return m_name; }

bool AForm::getIsSigned() const { return m_isSigned; }

int AForm::getGradeToSign() const { return m_gradeToSign; }

int AForm::getGradeToExecute() const { return m_gradeToExecute; }


const char* AForm::GradeTooHighException::what() const throw() { return "Form grade too high!"; }

const char* AForm::GradeTooLowException::what() const throw() { return "Form grade too low!"; }

const char* AForm::FormNotSignedException::what() const throw() { return "Form must be signed before executing it!"; }


void AForm::beSigned(const Bureaucrat& bureaucrat) {
    if (bureaucrat.getGrade() > m_gradeToSign) {
        throw Bureaucrat::GradeTooLowException();
    }

    m_isSigned = true;
}

void AForm::beExecuted(const Bureaucrat& bureaucrat) const {
    if (!m_isSigned) {
        throw FormNotSignedException();
    }

    if (executor.getGrade() > m_gradeToExecute) {
        throw Bureaucrat::GradeTooLowException();
    }

    executeAction();
}


std::ostream& operator<<(std::ostream& os, const AForm& f) {
    os << f.getName() << ": isSigned = " << (f.getIsSigned() ? "yes" : "no") << ", gradeToSign = " << f.getGradeToSign() << ", gradeToExecute = " << f.getGradeToExecute() << ".\n";
    return os;
}
