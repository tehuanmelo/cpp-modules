/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tehuanmelo <tehuanmelo@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 23:29:56 by tehuanmelo        #+#    #+#             */
/*   Updated: 2023/06/09 23:24:53 by tehuanmelo       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon() {}

Weapon::Weapon(std::string type) {
    this->type = type;
}

void Weapon::setType(std::string type) {
    this->type = type;
}

std::string Weapon::getType() {
    return this->type;
}

Weapon::~Weapon() {};