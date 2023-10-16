/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-melo <tde-melo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 21:11:04 by tehuanmelo        #+#    #+#             */
/*   Updated: 2023/10/06 16:49:45 by tde-melo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"
#include "../inc/Form.hpp"

int main()
{


    //// VALID FORM CREATION   
    try
    {
        Form fo1("Salary Letter", 10, 10); 
        
        std::cout << "\n\n";
        std::cout << fo1 << std::endl;
        std::cout << "\n\n";
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    //// INVALID FORM CREATION   
    // try
    // {
    //     Form fo1("Salary Letter", 200, 10); 
        
    //     std::cout << "\n\n";
    //     std::cout << fo1 << std::endl;
    //     std::cout << "\n\n";
    // }
    // catch(const std::exception& e)
    // {
    //     std::cerr << e.what() << '\n';
    // }
    
    //// VALID SIGNATURE TEST   
    // try
    // {
    //     Bureaucrat bu1("Ben Harper", 1);
    //     Form fo1("Salary Letter", 10, 10); 
        
    //     std::cout << "\n\n";
    //     std::cout << fo1 << std::endl;
    //     bu1.signForm(fo1);
    //     std::cout << "\n\n";
    // }
    // catch(const std::exception& e)
    // {
    //     std::cerr << e.what() << '\n';
    // }
    
    //// INVALID SIGNATURE TEST   
    // try
    // {
    //     Bureaucrat bu1("Ben Harper", 150);
    //     Form fo1("Salary Letter", 10, 10); 
        
    //     std::cout << "\n\n";
    //     std::cout << fo1 << std::endl;
    //     bu1.signForm(fo1);
    //     std::cout << "\n\n";
    // }
    // catch(const std::exception& e)
    // {
    //     std::cerr << e.what() << '\n';
    // }
    



    return 0;
}