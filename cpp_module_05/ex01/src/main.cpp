/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tehuanmelo <tehuanmelo@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 21:11:04 by tehuanmelo        #+#    #+#             */
/*   Updated: 2023/09/28 18:31:10 by tehuanmelo       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat a("Peter", 1);
        Bureaucrat b("Clark", 150);

        

        std::cout << a << std::endl;
        std::cout << b << std::endl;
        
        b.incrementGrade();
        std::cout << b << std::endl;

        a.incrementGrade();

    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
}