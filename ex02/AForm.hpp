#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
private:
    const std::string _name;
    bool              _isSigned;
    const int         _signGrade;
    const int         _executeGrade;

protected:
    
    virtual void executeAction() const = 0;

public:
    
    class GradeTooHighException : public std::exception
    {
        public:
            const char* what() const throw();
    };

    class GradeTooLowException : public std::exception
    {
        public:
            const char* what() const throw();
    };

    class FormNotSignedException : public std::exception
    {
        public:
            const char* what() const throw();
    };

    // Construtor e destrutor (Orthodox Canonical Form)

    AForm(const std::string& name, int signGrade, int executeGrade);
    AForm(const AForm& other);
    virtual ~AForm();
    AForm& operator=(const AForm& rhs);

    // Getters

    const std::string& getName() const;
    bool               getIsSigned() const;
    int                getSignGrade() const;
    int                getExecuteGrade() const;

    // Métodos principais

    void beSigned(const Bureaucrat& bureaucrat);
    void execute(const Bureaucrat& executor) const;
};

std::ostream& operator<<(std::ostream& os, const AForm& form);

#endif