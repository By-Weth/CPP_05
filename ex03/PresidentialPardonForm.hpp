#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"
#include <string>

class PresidentialPardonForm : public AForm
{
private:
    std::string _target;

protected:
    // Implementação da ação específica (virtual pura da classe base)
    virtual void executeAction() const;

public:
    // Orthodox Canonical Form
    PresidentialPardonForm(const std::string& target);
    PresidentialPardonForm(const PresidentialPardonForm& other);
    virtual ~PresidentialPardonForm();
    PresidentialPardonForm& operator=(const PresidentialPardonForm& rhs);

    // Getter para o target
    const std::string& getTarget() const;
};

#endif