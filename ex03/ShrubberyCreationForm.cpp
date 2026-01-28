#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include <fstream>

// Construtor
ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
    : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
}

// Copy constructor
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
    : AForm(other), _target(other._target)
{
}

// Destrutor
ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

// Operador de atribuição
ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& rhs)
{
    if (this != &rhs)
    {
        AForm::operator=(rhs);
        _target = rhs._target;
    }
    return *this;
}

// Getter
const std::string& ShrubberyCreationForm::getTarget() const
{
    return _target;
}

// Implementação da ação específica
void ShrubberyCreationForm::executeAction() const
{
    std::string filename = _target + "_shrubbery";
    std::ofstream outfile(filename.c_str());
    
    if (!outfile.is_open())
    {
        std::cerr << "Error: Could not create file " << filename << std::endl;
        return;
    }
    
    outfile << "       ###" << std::endl;
    outfile << "      #o###" << std::endl;
    outfile << "    #####o###" << std::endl;
    outfile << "   #o#\\#|#/###" << std::endl;
    outfile << "    ###\\|/#o#" << std::endl;
    outfile << "     # }|{  #" << std::endl;
    outfile << "       }|{" << std::endl;
    outfile << std::endl;
    outfile << "      ^^^^^" << std::endl;
    outfile << "     ^^^^^^^ " << std::endl;
    outfile << "    ^^^^^^^^^" << std::endl;
    outfile << "   ^^^^^^^^^^^" << std::endl;
    outfile << "      | |" << std::endl;
    outfile << "      | |" << std::endl;
    
    outfile.close();
    std::cout << "Shrubbery has been planted at " << filename << std::endl;
}