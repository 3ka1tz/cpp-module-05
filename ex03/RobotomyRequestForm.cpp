#include "RobotomyRequestForm.hpp"

#include <cstdlib>
#include <iostream>

RobotomyRequestForm::RobotomyRequestForm() :
    AForm("Default Robotomy Request Form", 72, 45),
    m_target("Default Target")
{}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) :
    AForm("Robotomy Request Form", 72, 45),
    m_target(target)
{}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) :
    AForm(other),
    m_target(other.m_target)
{}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
    if (this != &other) {
        AForm::operator=(other);
        m_target = other.m_target;
    }
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}


void RobotomyRequestForm::executeAction() const {
    std::cout << "Drilling noises...\n";

    if (rand() % 2 == 0) {
        std::cout << m_target << " has been robotomized.\n";
    } else {
        std::cout << m_target << " robotomy failed.\n";
    }
}
