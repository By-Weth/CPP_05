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

int main(void)
{
    try {
            Bureaucrat a("Elon Musk", 150);
            a.decrementGrade();
            std::cout << a << std::endl;
            a.incrementGrade();
    }
    catch(std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    return (0);
}
