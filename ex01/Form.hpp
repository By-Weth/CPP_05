#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include <exception>

class Bureaucrat;

class Form {

    private:

        const std::string name;
        const int signGrade;
        const int executeGrade;
        bool isSigned;
    
    public:

        Form(const std::string& name,  int signGrade, int executeGrade);

       std::string getName() const;
       bool getIsSigned() const;
       int getSignGrade() const;
       int getExecuteGrade() const;
       bool beSigned(const Bureaucrat& bureaucrat);

    
    class GradeTooHighException: public std::exception {

        public:
            const char* what() const throw();
    };

    class GradeTooLowException: public std::exception {

        public:
            const char* what() const throw();
    };
    
};

std::ostream& operator<<(std::ostream& os, const Form& form);

#endif