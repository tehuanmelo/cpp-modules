/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tehuanmelo <tehuanmelo@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 14:09:39 by tehuanmelo        #+#    #+#             */
/*   Updated: 2023/11/29 20:55:56 by tehuanmelo       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/RPN.hpp"


int main(int ac, char **av)
{

    if (ac == 2)
    {
        RPN RPNCalculator;
        std::string input = av[1];

        if (!RPNCalculator.readInput(input))
        {
            std::cerr << "Error" << std::endl;
            return 1;
        }
        double value = static_cast<int>(RPNCalculator.getStackTop());
        if (value == RPNCalculator.getStackTop())
            std::cout << value << std::endl;
        else    
            std::cout << RPNCalculator.getStackTop() << std::endl;
    }
    else
    {
        std::cerr << "Error" << std::endl;
        return 1;
    }

    return 0;
}