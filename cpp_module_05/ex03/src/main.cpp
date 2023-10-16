/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-melo <tde-melo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 21:11:04 by tehuanmelo        #+#    #+#             */
/*   Updated: 2023/10/06 18:09:27 by tde-melo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"
#include "../inc/Form.hpp"
#include "../inc/Intern.hpp"
#include "../inc/ShrubberyCreationForm.hpp"
#include "../inc/RobotomyRequestForm.hpp"
#include "../inc/PresidentialPardonForm.hpp"

int main()
{
   
    try
    {
        Intern formMaker;
        Bureaucrat b("name", 1);
        Form *form[3] = {
            formMaker.makeForm("ShrubberyCreationForm", "shrubbery"),
            formMaker.makeForm("RobotomyRequestForm", "shrubbery"),
            formMaker.makeForm("PresidentialPardonForm", "shrubbery")
        };
    
        for (size_t i = 0; i < 3; i++)
        {
            std::cout << form[i]->getName() << std::endl;
            b.signForm(*form[i]);
            form[i]->execute(b);
            delete form[i];
        }
    
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    return 0;
}