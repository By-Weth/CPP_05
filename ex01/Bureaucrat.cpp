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
#include "Form.hpp"

Bureaucrat::Bureaucrat(): name("Bureaucrat")
{
    this->grade = 1;
    std::cout << "Default Constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, int grade) : name(name)
{
    if (grade < 1)
        throw Bureaucrat::GradeTooHightException();
    else if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
    else {
        this->grade = grade;
    }
    std::cout << "Constructor called" << std::endl;
}


Bureaucrat::Bureaucrat(const Bureaucrat& other): name(other.name), grade(other.grade)
{
    std::cout << "Copy Constructor called" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other){
    if (this != &other)
    {
            this->grade = other.grade;
            std::cout << "Copy assigment called" << std::endl;
    }
    return *this;
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "Default Destructor called" << std::endl;
}

const char* Bureaucrat::GradeTooHightException::what() const throw() {
    return("Grade too Hight");
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return("Grade too Low");
}

std::string Bureaucrat::getName() const
{
    return (this->name);
}

int Bureaucrat::getGrade() const
{
    return (this->grade);
}



void Bureaucrat::incrementGrade()
{
    if (grade <= 1)
        throw Bureaucrat::GradeTooHightException();
    this->grade -= 1;
}

void Bureaucrat::decrementGrade()
{
    if (grade >= 150)
        throw Bureaucrat::GradeTooLowException();
    this->grade += 1;
}

void Bureaucrat::signForm(Form& form)
{
    try {
        form.beSigned(*this);
        std::cout << this->getName() << " signed " << form.getName() << std::endl;
    }
    catch (const std::exception& e ){
        std::cout << this->getName() << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
    }
    
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& other)
{
    os << other.getName() << ", grade " << other.getGrade() << std::endl;
    return os;
}
