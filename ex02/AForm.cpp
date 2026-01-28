#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <string>


const char* AForm::GradeTooHighException::what() const throw()
{
    return "Grade too high";
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return "Grade too low";
}

const char* AForm::FormNotSignedException::what() const throw()
{
    return "Form not signed";
}


AForm::AForm(const std::string& name, int signGrade, int executeGrade)
    : _name(name), _isSigned(false), _signGrade(signGrade), _executeGrade(executeGrade)
{
    if (signGrade < 1 || executeGrade < 1)
        throw AForm::GradeTooHighException();
    if (signGrade > 150 || executeGrade > 150)
        throw AForm::GradeTooLowException();
}

// === Construtor de cópia (não pode modificar atributos const, mas copia estado) ===

AForm::AForm(const AForm& other)
    : _name(other._name),
      _isSigned(other._isSigned),
      _signGrade(other._signGrade),
      _executeGrade(other._executeGrade)
{
}


AForm::~AForm()
{
    // Pode ser vazio
}

AForm& AForm::operator=(const AForm& rhs)
{
    // Não é possível modificar _name, _signGrade, _executeGrade (são const)
    // Então só copiamos o estado mutável
    if (this != &rhs)
    {
        // _isSigned é o único campo mutável
        const_cast<bool&>(_isSigned) = rhs._isSigned;
    }
    return *this;
}

// === Getters ===

const std::string& AForm::getName() const
{
    return _name;
}

bool AForm::getIsSigned() const
{
    return _isSigned;
}

int AForm::getSignGrade() const
{
    return _signGrade;
}

int AForm::getExecuteGrade() const
{
    return _executeGrade;
}

// === beSigned ===

void AForm::beSigned(const Bureaucrat& bureaucrat)
{
    if (bureaucrat.getGrade() > _signGrade)
        throw AForm::GradeTooLowException();
    _isSigned = true;
}

// === execute ===

void AForm::execute(const Bureaucrat& executor) const
{
    if (!_isSigned)
        throw AForm::FormNotSignedException();
    if (executor.getGrade() > _executeGrade)
        throw AForm::GradeTooLowException();
    executeAction(); // chamada virtual para a subclasse
}

// === Operador << ===

std::ostream& operator<<(std::ostream& os, const AForm& form)
{
    os << form.getName()
       << ", signed: " << (form.getIsSigned() ? "true" : "false")
       << ", sign grade: " << form.getSignGrade()
       << ", execute grade: " << form.getExecuteGrade();
    return os;
}