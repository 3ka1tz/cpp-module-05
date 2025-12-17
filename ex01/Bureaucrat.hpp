#pragma once

#include <exception>
#include <ostream>
#include <string>

class Form;

class Bureaucrat
{
    public:
        Bureaucrat();
        Bureaucrat(const std::string& name, int grade);
        Bureaucrat(const Bureaucrat& other);
        Bureaucrat& operator=(const Bureaucrat& other);
        ~Bureaucrat();

        const std::string& getName() const;
        int getGrade() const;

        void incrementGrade();
        void decrementGrade();

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

        void signForm(Form& form) const;

    private:
        const std::string name;
        int grade;
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);
