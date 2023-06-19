/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tehuanmelo <tehuanmelo@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 16:23:33 by tehuanmelo        #+#    #+#             */
/*   Updated: 2023/06/19 20:03:21 by tehuanmelo       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"


int main() {
    
    ScavTrap b("XXX-333");
    ScavTrap a("YYY-812");
    // ScavTrap c(b);
    // ScavTrap d("AAA-213");
    // d = c;
    b.attack("fff-78");
    a.takeDamage(4);
    a.beRepaired(10);
    b.guardGate();
    b.guardGate();
}