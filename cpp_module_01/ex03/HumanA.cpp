/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tehuanmelo <tehuanmelo@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 23:41:14 by tehuanmelo        #+#    #+#             */
/*   Updated: 2023/06/09 23:38:55 by tehuanmelo       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "Weapon.hpp"


HumanA::HumanA(std::string name, Weapon &weapon) : weapon(&weapon) {
    this->name = name;
}

void HumanA::attack() {
    std::cout << this->name << " attacks with their " << this->weapon->getType() << std::endl;
}

HumanA::~HumanA() {};