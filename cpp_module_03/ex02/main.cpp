/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-melo <tde-melo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 16:23:33 by tehuanmelo        #+#    #+#             */
/*   Updated: 2023/06/28 11:23:38 by tde-melo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "FragTrap.hpp"


int main() {
    
    FragTrap a("AAA-123");
    FragTrap b("BBB-234");
    FragTrap c(b);
    c = a;
    a.attack("XXX-345");
    b.takeDamage(20);
    b.beRepaired(10);
    c.highFiveGuys();
}