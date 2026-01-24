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

#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    std::cout << "=== Teste 1: Criando formulários com grades válidas ===" << std::endl;
    try {
        Form validForm("Valid Form", 50, 25);
        std::cout << validForm << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Erro inesperado: " << e.what() << std::endl;
    }

    std::cout << "\n=== Teste 2: Formulário com grade de assinatura muito alta (inválida) ===" << std::endl;
    try {
        Form highGradeForm("High Grade Form", 0, 50); // 0 < 1 → GradeTooHighException
    } catch (const Form::GradeTooHighException& e) {
        std::cout << "Capturado corretamente: " << e.what() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Erro inesperado: " << e.what() << std::endl;
    }

    std::cout << "\n=== Teste 3: Formulário com grade de execução muito baixa (inválida) ===" << std::endl;
    try {
        Form lowGradeForm("Low Grade Form", 100, 151); // 151 > 150 → GradeTooLowException
    } catch (const Form::GradeTooLowException& e) {
        std::cout << "Capturado corretamente: " << e.what() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Erro inesperado: " << e.what() << std::endl;
    }

    std::cout << "\n=== Teste 4: Ambas as grades inválidas (alta demais) ===" << std::endl;
    try {
        Form bothInvalid("Both Invalid", -10, 0);
    } catch (const Form::GradeTooHighException& e) {
        std::cout << "Capturado corretamente: " << e.what() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Erro inesperado: " << e.what() << std::endl;
    }

    std::cout << "\n=== Teste 5: Burocrata assina formulário com sucesso ===" << std::endl;
    try {
        Bureaucrat alice("Alice", 30);
        Form secretDoc("Secret Document", 40, 20); // Alice (30) <= 40 → pode assinar
        std::cout << "Antes: " << secretDoc << std::endl;
        alice.signForm(secretDoc);
        std::cout << "Depois: " << secretDoc << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Erro inesperado: " << e.what() << std::endl;
    }

    std::cout << "\n=== Teste 6: Burocrata NÃO pode assinar (grau insuficiente) ===" << std::endl;
    try {
        Bureaucrat bob("Bob", 100);
        Form topSecret("Top Secret", 50, 10); // Bob (100) > 50 → não pode assinar
        std::cout << "Antes: " << topSecret << std::endl;
        bob.signForm(topSecret);
        std::cout << "Depois: " << topSecret << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Erro inesperado: " << e.what() << std::endl;
    }

    std::cout << "\n=== Teste 7: Tentativa direta de beSigned() com burocrata não qualificado ===" << std::endl;
    try {
        Bureaucrat charlie("Charlie", 120);
        Form contract("Contract", 100, 50);
        contract.beSigned(charlie); // Deve lançar exceção
    } catch (const Form::GradeTooLowException& e) {
        std::cout << "Capturado corretamente ao chamar beSigned(): " << e.what() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Erro inesperado: " << e.what() << std::endl;
    }

    std::cout << "\n=== Teste 8: Formulário já assinado – tentar assinar novamente ===" << std::endl;
    try {
        Bureaucrat diana("Diana", 10);
        Form memo("Memo", 20, 15);
        diana.signForm(memo); // Primeira assinatura: sucesso
        diana.signForm(memo); // Segunda assinatura: deve imprimir mensagem de sucesso novamente?
        // Nota: o enunciado não proíbe re-assinatura, mas isSigned já é true.
        // A lógica aceita re-chamada, mas não muda nada.
        std::cout << memo << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Erro inesperado: " << e.what() << std::endl;
    }

    std::cout << "\n=== Teste 9: Burocrata com grau 1 (máximo) assina formulário com grau 1 ===" << std::endl;
    try {
        Bureaucrat god("God", 1);
        Form divineForm("Divine Form", 1, 1);
        god.signForm(divineForm);
        std::cout << divineForm << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Erro inesperado: " << e.what() << std::endl;
    }

    std::cout << "\n=== Teste 10: Burocrata com grau 150 (mínimo) tenta assinar formulário que exige grau 150 ===" << std::endl;
    try {
        Bureaucrat intern("Intern", 150);
        Form boringForm("Boring Form", 150, 150);
        intern.signForm(boringForm);
        std::cout << boringForm << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Erro inesperado: " << e.what() << std::endl;
    }

    std::cout << "\n=== Teste 11: Burocrata grau 150 tenta assinar formulário que exige grau 149 → falha ===" << std::endl;
    try {
        Bureaucrat intern("Intern", 150);
        Form slightlyImportant("Slightly Important", 149, 100);
        intern.signForm(slightlyImportant);
    } catch (const std::exception& e) {
        std::cerr << "Erro inesperado: " << e.what() << std::endl;
    }

    std::cout << "\n=== Fim dos testes ===" << std::endl;
    return 0;
}