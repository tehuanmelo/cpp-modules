/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tehuanmelo <tehuanmelo@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 16:23:33 by tehuanmelo        #+#    #+#             */
/*   Updated: 2023/06/19 18:52:03 by tehuanmelo       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"


int main() {
    
    ClapTrap a("IG-11");
    ClapTrap b("C-3PO");
    ClapTrap c(a);
    c = b;
    a.attack("C-3PO");
    b.takeDamage(5);
    b.takeDamage(5);
    b.takeDamage(5);
    b.beRepaired(5);
}