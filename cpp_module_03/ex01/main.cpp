/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-melo <tde-melo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 16:23:33 by tehuanmelo        #+#    #+#             */
/*   Updated: 2023/06/28 10:20:37 by tde-melo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"


int main() {
    
    ScavTrap a("AAA-812");
    ScavTrap b("BBB-333");
    ScavTrap c(a);
    c = b;
    a.attack("XXX-78");
    b.takeDamage(20);
    b.beRepaired(5);
    a.guardGate();
    a.guardGate();
}