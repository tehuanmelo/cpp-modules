/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tehuanmelo <tehuanmelo@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 16:23:33 by tehuanmelo        #+#    #+#             */
/*   Updated: 2023/06/24 16:06:53 by tehuanmelo       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "FragTrap.hpp"


int main() {
    
    FragTrap b("XXX-333");
    FragTrap a("YYY-812");
    FragTrap c(b);
    c = a;
    b.attack("fff-78");
    a.takeDamage(4);
    a.beRepaired(10);
    b.highFivesGuys();
    c.attack("asdf");
}