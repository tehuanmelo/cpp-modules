/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-melo <tde-melo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 23:41:14 by tehuanmelo        #+#    #+#             */
/*   Updated: 2023/06/26 13:51:14 by tde-melo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "Weapon.hpp"


HumanA::HumanA(std::string name, Weapon &weapon) {
    this->name = name;
    this->weapon = &weapon;
}

void HumanA::attack() {
    std::cout << this->name << " attacks with their " << this->weapon->getType() << std::endl;
}

HumanA::~HumanA() {};