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

#include "Intern.hpp"
#include <iostream>

int main()
{
    Intern intern;

    // === Testes com nomes válidos ===
    
    std::cout << ">>> Testando criação de formulários válidos:\n" << std::endl;

    AForm* f1 = intern.makeForm("shrubbery creation", "home");
    if (f1) {
        std::cout << "✓ Criado: " << f1->getName() << " (alvo: home)" << std::endl;
        delete f1;
    }

    AForm* f2 = intern.makeForm("robotomy request", "Bender");
    if (f2) {
        std::cout << "✓ Criado: " << f2->getName() << " (alvo: Bender)" << std::endl;
        delete f2;
    }

    AForm* f3 = intern.makeForm("presidential pardon", "Arthur Dent");
    if (f3) {
        std::cout << "✓ Criado: " << f3->getName() << " (alvo: Arthur Dent)" << std::endl;
        delete f3;
    }

    // === Testes com nomes inválidos ===
    
    std::cout << "\n>>> Testando nomes inválidos:\n" << std::endl;

    AForm* f4 = intern.makeForm("coffee order", "Bob");
    if (!f4) {
        std::cout << "✓ Rejeitado corretamente: 'coffee order'" << std::endl;
    }

    AForm* f5 = intern.makeForm("Presidential Pardon", "Ford"); // maiúscula + espaço errado
    if (!f5) {
        std::cout << "✓ Rejeitado corretamente: nome com maiúscula ('Presidential Pardon')" << std::endl;
    }

    AForm* f6 = intern.makeForm("", "Nobody");
    if (!f6) {
        std::cout << "✓ Rejeitado corretamente: nome vazio" << std::endl;
    }

    std::cout << "\n✅ Todos os testes do Intern concluídos." << std::endl;
    return 0;
}