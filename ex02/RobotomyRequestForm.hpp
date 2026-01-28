#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <string>

class RobotomyRequestForm : public AForm
{
private:
    std::string _target;

protected:
    // Implementação da ação específica (virtual pura da classe base)
    virtual void executeAction() const;

public:
    // Orthodox Canonical Form
    RobotomyRequestForm(const std::string& target);
    RobotomyRequestForm(const RobotomyRequestForm& other);
    virtual ~RobotomyRequestForm();
    RobotomyRequestForm& operator=(const RobotomyRequestForm& rhs);

    // Getter para o target
    const std::string& getTarget() const;
};

#endif