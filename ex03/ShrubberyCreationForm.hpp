#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <string>

class ShrubberyCreationForm : public AForm
{
private:
    std::string _target;

protected:
    // Implementação da ação específica (virtual pura da classe base)
    virtual void executeAction() const;

public:
    // Orthodox Canonical Form
    ShrubberyCreationForm(const std::string& target);
    ShrubberyCreationForm(const ShrubberyCreationForm& other);
    virtual ~ShrubberyCreationForm();
    ShrubberyCreationForm& operator=(const ShrubberyCreationForm& rhs);

    // Getter para o target
    const std::string& getTarget() const;
};

#endif