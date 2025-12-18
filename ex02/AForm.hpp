#pragma once

#include <exception>
#include <ostream>
#include <string>

class Bureaucrat;

class AForm
{
    public:
        AForm();
        AForm(const std::string& name, const int gradeToSign, const int gradeToExecute);
        AForm(const AForm& other);
        AForm& operator=(const AForm& other);
        ~AForm();

        const std::string& getName() const;
        bool getIsSigned() const;
        int getGradeToSign() const;
        int getGradeToExecute() const;

        class GradeTooHighException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };

        class GradeTooLowException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };

        class FormNotSignedException : public std::exception {
            public:
                virtual const char* what() const throw();
        };

        void beSigned(const Bureaucrat& bureaucrat);
        void beExecuted(const Bureaucrat& bureaucrat) const;

    protected:
        virtual void executeAction() const = 0;

    private:
        const std::string name;
        bool isSigned;
        const int gradeToSign;
        const int gradeToExecute;
};

std::ostream& operator<<(std::ostream& os, const AForm& f);
