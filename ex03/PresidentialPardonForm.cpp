#include "PresidentialPardonForm.hpp"

#include <iostream>

PresidentialPardonForm::PresidentialPardonForm() :
    AForm("Default Presidential Pardon Form", 25, 5),
    m_target("Default Target")
{}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target) :
    AForm("Presidential Pardon Form", 25, 5),
    m_target(target)
{}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) :
    AForm(other),
    m_target(other.m_target)
{}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other) {
    if (this != &other) {
        AForm::operator=(other);
        m_target = other.m_target;
    }
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {}


void PresidentialPardonForm::executeAction() const {
    std::cout << m_target << " has been pardoned by Zaphod Beeblebrox.\n";
}
