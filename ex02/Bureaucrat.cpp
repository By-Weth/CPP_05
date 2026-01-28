/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpascoal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 11:05:24 by mpascoal          #+#    #+#             */
/*   Updated: 2026/01/20 11:05:28 by mpascoal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

// Construtor padrão
Bureaucrat::Bureaucrat() : name("Default"), grade(150)
{
}

// Construtor parametrizado
Bureaucrat::Bureaucrat(const std::string name, int grade) : name(name)
{
    if (grade < 1)
        throw GradeTooHightException();
    if (grade > 150)
        throw GradeTooLowException();
    this->grade = grade;
}

// Copy constructor
Bureaucrat::Bureaucrat(const Bureaucrat& other) : name(other.name), grade(other.grade)
{
}

// Destrutor
Bureaucrat::~Bureaucrat()
{
}

// Operador de atribuição
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
    if (this != &other)
    {
        this->grade = other.grade;
        // name é const, não pode ser alterado
    }
    return *this;
}

// Getters
int Bureaucrat::getGrade() const
{
    return this->grade;
}

std::string Bureaucrat::getName() const
{
    return this->name;
}

// Incrementar grade (diminui o número)
void Bureaucrat::incrementGrade()
{
    if (this->grade - 1 < 1)
        throw GradeTooHightException();
    this->grade--;
}

// Decrementar grade (aumenta o número)
void Bureaucrat::decrementGrade()
{
    if (this->grade + 1 > 150)
        throw GradeTooLowException();
    this->grade++;
}

// Assinar formulário
void Bureaucrat::signForm(AForm& form)
{
    try
    {
        form.beSigned(*this);
        std::cout << this->name << " signed " << form.getName() << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << this->name << " couldn't sign " << form.getName() 
                  << " because " << e.what() << std::endl;
    }
}

// NOVO: Executar formulário
void Bureaucrat::executeForm(const AForm& form) const
{
    try
    {
        form.execute(*this);
        std::cout << this->name << " executed " << form.getName() << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << this->name << " couldn't execute " << form.getName() 
                  << " because " << e.what() << std::endl;
    }
}

// Exceções
const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Grade is too low!";
}

const char* Bureaucrat::GradeTooHightException::what() const throw()
{
    return "Grade is too high!";
}

// Operador de inserção
std::ostream& operator<<(std::ostream& os, const Bureaucrat& other)
{
    os << other.getName() << ", bureaucrat grade " << other.getGrade();
    return os;
}