#include "Form.hpp"
#include "Bureaucrat.hpp" 

Form::Form(const std::string& name, int signGrade, int executeGrade )
    :name(name), signGrade(signGrade), executeGrade(executeGrade), isSigned(false)
{
    if (this->signGrade < 1 || this->executeGrade < 1)
        throw Form::GradeTooHighException();
    else if (this->signGrade > 150 || this->executeGrade > 150)
        throw Form::GradeTooLowException();
    else
        std::cout << "Form constructor called." << std::endl;
}

std::string Form::getName() const {
    return (this->name);
}

bool Form::getIsSigned() const {

    return (this->isSigned);
}

int Form::getSignGrade() const {

    return (this->signGrade);
}

int Form::getExecuteGrade() const {

    return (this->executeGrade);
}

const char* Form::GradeTooHighException::what() const throw() {
    return("Grade too High");
}

const char* Form::GradeTooLowException::what() const throw() {
    return("Grade too Low");
}


bool Form::beSigned(const Bureaucrat& bureaucrat)
{
    if (bureaucrat.getGrade() <= this->signGrade)
        this->isSigned = true;
    else
        throw Form::GradeTooLowException();
    return (true);

}

std::ostream& operator<<(std::ostream& os, const Form& form)
{
    os << form.getName() <<  " signed: " << form.getIsSigned() << " sign grade: " << form.getSignGrade() << " execute grade: " << form.getExecuteGrade() << std::endl;
    return os;
}