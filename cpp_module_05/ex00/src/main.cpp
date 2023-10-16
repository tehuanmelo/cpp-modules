/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-melo <tde-melo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 21:11:04 by tehuanmelo        #+#    #+#             */
/*   Updated: 2023/10/06 16:24:04 by tde-melo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"

int main()
{


    /// OBJECT CREATION TEST
    try
    {
        Bureaucrat bu("Ben Harper", 50);
        std::cout << "\n" << bu << "\n";
        bu.incrementGrade();
        std::cout << bu << "\n";
        bu.decrementGrade();
        std::cout << bu << "\n\n";
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
    
    ///// INVALID CREATION TEST
    ///// GRADE TO HIGH EXCEPTION
    // try
    // {
    //     Bureaucrat bu("Ben Harper", 0);
    // }
    // catch (const std::exception &e)
    // {
    //     std::cerr << e.what() << '\n';
    // }
    
    ///// INVALID CREATION TEST
    ///// GRADE TO LOW EXCEPTION
    // try
    // {
    //     Bureaucrat bu("Ben Harper", 151);
    // }
    // catch (const std::exception &e)
    // {
    //     std::cerr << e.what() << '\n';
    // }

    ///// OBJECT DECREMENT EXCEPTION
    // try
    // {
    //     Bureaucrat bu("Ben Harper", 150);
    //     std::cout << "\n" << bu << "\n";
    //     bu.decrementGrade();
    // }
    // catch (const std::exception &e)
    // {
    //     std::cerr << e.what() << '\n';
    // }
    
    ///// OBJECT INCREMENT EXCEPTION
    // try
    // {
    //     Bureaucrat bu("Ben Harper", 1);
    //     std::cout << "\n" << bu << "\n";
    //     bu.incrementGrade();
    // }
    // catch (const std::exception &e)
    // {
    //     std::cerr << e.what() << '\n';
    // }

    return 0;
}