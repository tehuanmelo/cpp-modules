/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tehuanmelo <tehuanmelo@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 15:13:10 by tehuanmelo        #+#    #+#             */
/*   Updated: 2023/06/11 12:53:57 by tehuanmelo       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int ac, char **av) {
    if (ac == 2) {
        std::string str = av[1];
        for (std::string::iterator it = str.begin(); it != str.end(); it++)
           *it = std::toupper(*it);
        Harl obj;
        obj.complain(str);
    }
    else
        std::cout << "[ INVALID INPUT ]" << std::endl;
}