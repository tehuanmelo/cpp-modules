/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tehuanmelo <tehuanmelo@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 16:23:33 by tehuanmelo        #+#    #+#             */
/*   Updated: 2023/06/19 17:44:34 by tehuanmelo       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"


int main() {
    
    ClapTrap a("IG-11");
    ClapTrap b("C-3PO");
    ClapTrap c(a);
    std::cout << "robot a name: " << a.getname() << std::endl;
    std::cout << "robot b name: " << b.getname() << std::endl;
    std::cout << "robot c name: " << c.getname() << std::endl;
    c = b;
    std::cout << "robot c name is: " << c.getname() << std::endl;
    a.attack("C-3PO");
    b.takeDamage(5);
    b.takeDamage(5);
    b.takeDamage(5);
    b.beRepaired(5);
}