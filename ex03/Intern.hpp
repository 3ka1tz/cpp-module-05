#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

#include <exception>
#include <string>

class Intern {
public:
    Intern();
    Intern(const Intern& other);
    Intern& operator=(const Intern& other);
    ~Intern();

    class NotExistingFormException : public std::exception {
    public:
        virtual const char* what() const throw();
    };

    AForm* makeForm(const std::string& formName, const std::string& formTarget) const;
};

#endif // INTERN_HPP
