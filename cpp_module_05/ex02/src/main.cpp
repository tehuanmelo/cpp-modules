/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tehuanmelo <tehuanmelo@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 21:11:04 by tehuanmelo        #+#    #+#             */
/*   Updated: 2023/10/04 22:14:13 by tehuanmelo       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"
#include "../inc/AForm.hpp"
#include "../inc/ShrubberyCreationForm.hpp"
#include "../inc/RobotomyRequestForm.hpp"
#include "../inc/PresidentialPardonForm.hpp"

int main()
{
    Bureaucrat bu("Jack Johnson", 1);
    Bureaucrat bu2("Ben Harper", 150);
    ShrubberyCreationForm sh("Mars");
    RobotomyRequestForm rb("Bob Marley");
    PresidentialPardonForm pr("Jimmy Hendrixx");
    
    std::cout << "\n\n\n";
    
    try
    {
        std::cout << "\n";
        std::cout << sh << std::endl;
        std::cout << "\n";
        std::cout << rb << std::endl;
        std::cout << "\n";
        std::cout << pr << std::endl;
        std::cout << "\n";
        
        bu.signForm(sh);
        bu.signForm(rb);
        bu.signForm(pr);
        bu.executeForm(rb);
        bu.executeForm(pr);
        bu.executeForm(sh);
        
        std::cout << "\n";
        std::cout << sh << std::endl;
        std::cout << "\n";
        std::cout << rb << std::endl;
        std::cout << "\n";
        std::cout << pr << std::endl;
        std::cout << "\n";
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
  

    std::cout << "\n\n\n";

    return 0;
}