#include "PresidentialPardonForm.hpp"
#include <iostream>

// Construtor
PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
    : AForm("Presidential Pardon Form", 25, 5), _target(target)
{
}

// Copy constructor
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other)
    : AForm(other), _target(other._target)
{
}

// Destrutor
PresidentialPardonForm::~PresidentialPardonForm()
{
}

// Operador de atribuição
PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& rhs)
{
    if (this != &rhs)
    {
        AForm::operator=(rhs);
        _target = rhs._target;
    }
    return *this;
}

// Getter
const std::string& PresidentialPardonForm::getTarget() const
{
    return _target;
}

// Implementação da ação específica
void PresidentialPardonForm::executeAction() const
{
    std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}