#include "Intern.hpp"

#include <iostream>

Intern::Intern() {}

Intern::Intern(const Intern& other) {
    (void)other;
}

Intern& Intern::operator=(const Intern& other) {
    (void)other;
    return *this;
}

Intern::~Intern() {}


const char* Intern::NotExistingFormException::what() const throw() { return "Intern couldn't make form because provided form name doesn't exist."; }


AForm* Intern::makeForm(const std::string& formName, const std::string& formTarget) const {
    const std::string forms[3] = {"presidential pardon", "robotomy request", "shrubbery creation"};
    int i;

    for (i = 0; i < 3; ++i) {
        if (formName == forms[i]) {
            break;
        }
    }

    if (i < 3) {
        std::cout << "Intern creates " << formName << ".\n";
    }

    switch(i) {
        case 0:
            return new PresidentialPardonForm(formTarget);
        case 1:
            return new RobotomyRequestForm(formTarget);
        case 2:
            return new ShrubberyCreationForm(formTarget);
        default:
            throw NotExistingFormException();
    }
}
