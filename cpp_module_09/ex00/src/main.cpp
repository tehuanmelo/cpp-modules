/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tehuanmelo <tehuanmelo@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 14:09:39 by tehuanmelo        #+#    #+#             */
/*   Updated: 2023/11/22 22:33:40 by tehuanmelo       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/BitcoinExchange.hpp"

int main(int ac, char **av)
{
    if (ac == 2)
    {
        Btc bit;
        bit.loadInput(av[1]);
    }
    else
        std::cout << "Error: Could not open file." << std::endl;
    return 0;
}