#ifndef FORM_HPP
#define FORM_HPP

#include <exception>
#include <ostream>
#include <string>

class Bureaucrat;

class Form {
public:
    Form();
    Form(const std::string& name, const int gradeToSign, const int gradeToExecute);
    Form(const Form& other);
    Form& operator=(const Form& other);
    ~Form();

    const std::string& getName() const;
    bool getIsSigned() const;
    int getGradeToSign() const;
    int getGradeToExecute() const;

    class GradeTooHighException : public std::exception {
    public:
        virtual const char* what() const throw();
    };

    class GradeTooLowException : public std::exception {
    public:
        virtual const char* what() const throw();
    };

    void beSigned(const Bureaucrat& bureaucrat);

private:
    const std::string m_name;
    bool m_isSigned;
    const int m_gradeToSign;
    const int m_gradeToExecute;
};

std::ostream& operator<<(std::ostream& os, const Form& f);

#endif // FORM_HPP
