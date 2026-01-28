#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include <string>
#include "AForm.hpp"


class AForm;



class Intern {


    public:

        Intern();
        ~Intern();
        Intern(const Intern& other);
        Intern& operator=(const Intern& Other);

        AForm* makeForm(const std::string& formName, const std::string& target);
};
#endif