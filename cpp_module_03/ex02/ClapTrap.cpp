/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tehuanmelo <tehuanmelo@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 15:58:56 by tehuanmelo        #+#    #+#             */
/*   Updated: 2023/06/19 20:02:00 by tehuanmelo       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name) {
    std::cout << "ClapTrap constructor called" << std::endl;
    Name = name;
    HitPoints = 10;
    EnergyPoints = 10;
    AttackDamage = 0;
}

ClapTrap::ClapTrap(const ClapTrap& copy) {
    std::cout << "ClapTrap copy constructor called" << std::endl;
    *this = copy;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& copy) {
    std::cout << "ClapTrap copy assignment operator called" << std::endl;
    if (this != &copy) {
        Name = copy.Name;
        HitPoints = copy.HitPoints;
        EnergyPoints = copy.HitPoints;
        AttackDamage = copy.AttackDamage;
    }
    return *this;
}

ClapTrap::~ClapTrap() {
    std::cout << "ClapTrap " << Name << " destructor called" << std::endl;
}

void ClapTrap::attack(const std::string &target) {
    if (HitPoints > 0 && EnergyPoints > 0) {
        EnergyPoints--;
        std::cout << "ClapTrap " << Name << " attacks " << target << ", causing " << AttackDamage << " points of damage!" << std::endl;
    }
    else if (HitPoints == 0 )
        std::cout << "ClapTrap " << Name << " can't attack " << target << "it has no Hit Points." << std::endl;
    else 
        std::cout << "ClapTrap " << Name << " can't attack " << target << "it has no energy Points." << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
    if (HitPoints > amount) 
        HitPoints -= amount;
    else if (HitPoints > 0)
        HitPoints = 0;
    else  {
        std::cout << "ClapTrap " << Name << " can't suffer damage it's Hit points are already 0." << std::endl;
        return;
    }  
    std::cout << "ClapTrap " << Name << " suffered " << amount << " points of damage" << std::endl;
        
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (EnergyPoints > 0) {
        HitPoints += amount;
        EnergyPoints--;
        std::cout << "ClapTrap " << Name << " is repaired it's Hit Points are " <<  HitPoints << std::endl;
    }
    else    
        std::cout << "ClapTrap " << Name << " can't be repaired it's Energy Points are 0." << std::endl;
        
}
