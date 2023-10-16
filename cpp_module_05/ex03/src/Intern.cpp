/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-melo <tde-melo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 11:47:17 by tehuanmelo        #+#    #+#             */
/*   Updated: 2023/10/06 17:59:44 by tde-melo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Intern.hpp"

Intern::Intern() {
    std::cout << "Intern constructor called" << std::endl;
}

Intern::Intern(const Intern& copy) {
    (void)copy;
    std::cout << "Intern copy constructor called" << std::endl;
}

Intern& Intern::operator=(const Intern& copy) {
    (void)copy;
    std::cout << "Intern assignment operator called" << std::endl;
    return *this;
}

Intern::~Intern() {
    std::cout << "Intern deconstructor called" << std::endl;
}

Form* makeShrubberyForm(std::string target) {
        return new ShrubberyCreationForm(target);
}
    
Form* makeRobotomyForm(std::string target) {
    return new RobotomyRequestForm(target);
}
Form* makePresidentialForm(std::string target) {
    return new PresidentialPardonForm(target);
}

const char* Intern::FormDoesNotExist::what() const throw() {
    return "Form does not exist";
}

Form* Intern::makeForm(std::string formToCreate, std::string target) {
    Form *(*createFormList[])(std::string) = {makeShrubberyForm, makeRobotomyForm, makePresidentialForm};
    std::string formList[] = {"ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm"};
    for (int i = 0; i < 3; i++) {
        if (formList[i] == formToCreate) {
            std::cout << "Intern creates " << formToCreate << std::endl;
            return createFormList[i](target);
        }
    }
    throw Intern::FormDoesNotExist();
}