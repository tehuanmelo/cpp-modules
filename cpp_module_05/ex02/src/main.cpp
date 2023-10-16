/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-melo <tde-melo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 21:11:04 by tehuanmelo        #+#    #+#             */
/*   Updated: 2023/10/06 19:10:59 by tde-melo         ###   ########.fr       */
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
    ShrubberyCreationForm shrub("Home");
    RobotomyRequestForm robo("Bob Marley");
    PresidentialPardonForm pardon("Jimmy Hendrixx");
    
    std::cout << "\n\n\n";
    
    try
    {
        std::cout << "\n";
        std::cout << shrub << std::endl;
        std::cout << "\n";
        std::cout << robo << std::endl;
        std::cout << "\n";
        std::cout << pardon << std::endl;
        std::cout << "\n";
        
        bu.signForm(shrub);
        bu.signForm(robo);
        bu.signForm(pardon);
        bu.executeForm(robo);
        bu.executeForm(robo);
        bu.executeForm(robo);
        bu.executeForm(pardon);
        bu.executeForm(shrub);
        
        std::cout << "\n";
        std::cout << shrub << std::endl;
        std::cout << "\n";
        std::cout << robo << std::endl;
        std::cout << "\n";
        std::cout << pardon << std::endl;
        std::cout << "\n";
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
  

    std::cout << "\n\n\n";

    return 0;
}