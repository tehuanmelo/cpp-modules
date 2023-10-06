/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tehuanmelo <tehuanmelo@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 21:11:04 by tehuanmelo        #+#    #+#             */
/*   Updated: 2023/10/06 12:19:57 by tehuanmelo       ###   ########.fr       */
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
        Form *newForm;
        Bureaucrat te("Tehuan", 45);
        newForm = formMaker.makeForm("RobotomyRequestForm", "Ben");
        std::cout << "\n\n\n";
        
        te.signForm(*newForm);
        te.executeForm(*newForm);
        te.executeForm(*newForm);

        std::cout << *newForm << std::endl;
        std::cout << "\n\n\n";
        delete newForm;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
  


    return 0;
}