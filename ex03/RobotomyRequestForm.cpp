#include "RobotomyRequestForm.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

// Construtor
RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
    : AForm("Robotomy Request Form", 72, 45), _target(target)
{
}

// Copy constructor
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
    : AForm(other), _target(other._target)
{
}

// Destrutor
RobotomyRequestForm::~RobotomyRequestForm()
{
}

// Operador de atribuição
RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& rhs)
{
    if (this != &rhs)
    {
        AForm::operator=(rhs);
        _target = rhs._target;
    }
    return *this;
}

// Getter
const std::string& RobotomyRequestForm::getTarget() const
{
    return _target;
}

// Implementação da ação específica
void RobotomyRequestForm::executeAction() const
{
    std::cout << "* BZZZZZ... WHIRRRRR... DRILL DRILL DRILL *" << std::endl;
    
    // 50% de chance de sucesso
    std::srand(std::time(NULL));
    if (std::rand() % 2 == 0)
    {
        std::cout << _target << " has been robotomized successfully!" << std::endl;
    }
    else
    {
        std::cout << "Robotomy failed on " << _target << "." << std::endl;
    }
}