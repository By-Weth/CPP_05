/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpascoal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 11:05:32 by mpascoal          #+#    #+#             */
/*   Updated: 2026/01/20 11:05:36 by mpascoal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP


#include <string>
#include <exception>
#include <iostream>


class Bureaucrat {

    private:
        const std::string name;
        int grade;

    public:
        Bureaucrat();
        ~Bureaucrat();
        Bureaucrat(const std::string name, int grade);
        Bureaucrat(const Bureaucrat& other);
        Bureaucrat& operator=(const Bureaucrat& other);


        int getGrade() const;
        std::string getName() const;

        void incrementGrade();
        void decrementGrade();


        class GradeTooLowException : public std::exception {

            public:
                const char* what() const throw();
                

        };

        class GradeTooHightException : public std::exception {

            public:
                const char* what() const throw();

        };
};

 std::ostream& operator<<(std::ostream& os, const Bureaucrat& other);



#endif
