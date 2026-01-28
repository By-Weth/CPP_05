/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpascoal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 11:05:41 by mpascoal          #+#    #+#             */
/*   Updated: 2026/01/20 11:05:43 by mpascoal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

void printSeparator(const std::string& title)
{
    std::cout << "\n========== " << title << " ==========" << std::endl;
}

int main()
{
    printSeparator("TEST 1: ShrubberyCreationForm - SUCCESS");
    try
    {
        Bureaucrat bob("Bob", 120);
        ShrubberyCreationForm shrubbery("home");
        
        std::cout << bob << std::endl;
        std::cout << shrubbery << std::endl;
        
        bob.signForm(shrubbery);
        bob.executeForm(shrubbery);
    }
    catch (std::exception& e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    printSeparator("TEST 2: ShrubberyCreationForm - FAIL (not signed)");
    try
    {
        Bureaucrat alice("Alice", 100);
        ShrubberyCreationForm garden("garden");
        
        std::cout << alice << std::endl;
        alice.executeForm(garden);  // Não foi assinado!
    }
    catch (std::exception& e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    printSeparator("TEST 3: ShrubberyCreationForm - FAIL (grade too low to execute)");
    try
    {
        Bureaucrat charlie("Charlie", 145);
        ShrubberyCreationForm park("park");
        
        std::cout << charlie << std::endl;
        std::cout << park << std::endl;
        
        charlie.signForm(park);     // Pode assinar (145 >= 145)
        charlie.executeForm(park);  // Não pode executar (145 < 137)
    }
    catch (std::exception& e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    printSeparator("TEST 4: RobotomyRequestForm - SUCCESS");
    try
    {
        Bureaucrat dave("Dave", 40);
        RobotomyRequestForm robotomy("Bender");
        
        std::cout << dave << std::endl;
        std::cout << robotomy << std::endl;
        
        dave.signForm(robotomy);
        dave.executeForm(robotomy);
    }
    catch (std::exception& e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    printSeparator("TEST 5: RobotomyRequestForm - Multiple executions (50% chance)");
    try
    {
        Bureaucrat eve("Eve", 1);
        RobotomyRequestForm robo1("Target1");
        RobotomyRequestForm robo2("Target2");
        RobotomyRequestForm robo3("Target3");
        
        eve.signForm(robo1);
        eve.signForm(robo2);
        eve.signForm(robo3);
        
        std::cout << "\nExecution 1:" << std::endl;
        eve.executeForm(robo1);
        
        std::cout << "\nExecution 2:" << std::endl;
        eve.executeForm(robo2);
        
        std::cout << "\nExecution 3:" << std::endl;
        eve.executeForm(robo3);
    }
    catch (std::exception& e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    printSeparator("TEST 6: RobotomyRequestForm - FAIL (grade too low to sign)");
    try
    {
        Bureaucrat frank("Frank", 100);
        RobotomyRequestForm robotomy("Marvin");
        
        std::cout << frank << std::endl;
        frank.signForm(robotomy);  // Não pode assinar (100 < 72)
    }
    catch (std::exception& e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    printSeparator("TEST 7: PresidentialPardonForm - SUCCESS");
    try
    {
        Bureaucrat president("President", 1);
        PresidentialPardonForm pardon("Arthur Dent");
        
        std::cout << president << std::endl;
        std::cout << pardon << std::endl;
        
        president.signForm(pardon);
        president.executeForm(pardon);
    }
    catch (std::exception& e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    printSeparator("TEST 8: PresidentialPardonForm - FAIL (grade too low)");
    try
    {
        Bureaucrat george("George", 30);
        PresidentialPardonForm pardon("Ford Prefect");
        
        std::cout << george << std::endl;
        std::cout << pardon << std::endl;
        
        george.signForm(pardon);    // Não pode assinar (30 < 25)
        george.executeForm(pardon);
    }
    catch (std::exception& e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    printSeparator("TEST 9: Mixed forms with one bureaucrat");
    try
    {
        Bureaucrat superBureaucrat("SuperBureaucrat", 1);
        
        ShrubberyCreationForm tree("office");
        RobotomyRequestForm robot("Employee");
        PresidentialPardonForm pardon("Criminal");
        
        std::cout << superBureaucrat << std::endl;
        
        // Assina todos
        superBureaucrat.signForm(tree);
        superBureaucrat.signForm(robot);
        superBureaucrat.signForm(pardon);
        
        std::cout << std::endl;
        
        // Executa todos
        superBureaucrat.executeForm(tree);
        superBureaucrat.executeForm(robot);
        superBureaucrat.executeForm(pardon);
    }
    catch (std::exception& e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    printSeparator("TEST 10: All forms info display");
    try
    {
        ShrubberyCreationForm s("target1");
        RobotomyRequestForm r("target2");
        PresidentialPardonForm p("target3");
        
        std::cout << s << std::endl;
        std::cout << r << std::endl;
        std::cout << p << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    printSeparator("END OF TESTS");
    
    return 0;
}