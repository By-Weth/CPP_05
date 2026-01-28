// Intern.cpp
#include "Intern.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern() {
    std::cout << "Intern constructor called" << std::endl;
}

Intern::Intern(const Intern& other)
{
    (void)other;
    std::cout << "Intern copy constructor called" << std::endl;
}

Intern::~Intern() {}

Intern& Intern::operator=(const Intern& rhs)
{
    (void)rhs;
    std::cout << "Intern assignment constructor called" << std::endl;
    return *this;
}

AForm* Intern::makeForm(const std::string& formName, const std::string& target)
{
    // Lista dos nomes válidos (na mesma ordem que os cases)
    std::string names[3] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };

    for (int i = 0; i < 3; ++i)
    {
        if (formName == names[i])
        {
            std::cout << "Intern creates " << formName << std::endl;

            switch (i)
            {
                case 0:
                    return new ShrubberyCreationForm(target);
                case 1:
                    return new RobotomyRequestForm(target);
                case 2:
                    return new PresidentialPardonForm(target);
            }
        }
    }

    std::cout << "Error: form \"" << formName << "\" not found." << std::endl;
    return 0;
}