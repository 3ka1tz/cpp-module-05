#include "ShrubberyCreationForm.hpp"

#include <fstream>
#include <iostream>
#include <stdexcept>

ShrubberyCreationForm::ShrubberyCreationForm() :
    AForm("Default Shrubbery Creation Form", 145, 137),
    m_target("default_target")
{}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) :
    AForm("Shrubbery Creation Form", 145, 137),
    m_target(target)
{}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) :
    AForm(other),
    m_target(other.m_target)
{}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
    if (this != &other) {
        AForm::operator=(other);
        m_target = other.m_target;
    }
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}


void ShrubberyCreationForm::executeAction() const {
    const std::string filename = m_target + "_shrubbery";

    std::ofstream ofs(filename.c_str());
    if (!ofs) {
        throw std::runtime_error(filename + "file creation failed.\n");
    }

    ofs << "    *          *\n"
        << "   ***        ***\n"
        << "  *****      *****\n"
        << " *******    *******\n"
        << "*********  *********\n"
        << "   | |        | |\n";

    std::cout << filename << " file created.\n";
}
