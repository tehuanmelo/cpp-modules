/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tehuanmelo <tehuanmelo@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 18:52:35 by tehuanmelo        #+#    #+#             */
/*   Updated: 2023/06/27 22:25:51 by tehuanmelo       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
    std::cout << "ScavTrap constructor called" << std::endl;
    HitPoints = 100;
    EnergyPoints = 50;
    AttackDamage = 20;
    Gate = false;
}

ScavTrap::ScavTrap(const ScavTrap& copy) : ClapTrap(copy) {
    Gate = copy.Gate;
    std::cout << "ScavTrap copy constructor called" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& copy) {
    std::cout << "ScavTrap copy assignment operator called" << std::endl;
    if (this != &copy) {
        Name = copy.Name;
        HitPoints = copy.HitPoints;
        EnergyPoints = copy.HitPoints;
        AttackDamage = copy.AttackDamage;
        Gate = copy.Gate;
    }
    return *this;
}

ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap " << Name << " destructor called" << std::endl;
}

void ScavTrap::attack(const std::string &target) {
    if (HitPoints > 0 && EnergyPoints > 0) {
        EnergyPoints--;
        std::cout << "ScavTrap " << Name << " attacks " << target << ", causing " << AttackDamage << " points of damage!" << std::endl;
    }
    else if (HitPoints == 0 )
        std::cout << "ScavTrap " << Name << " can't attack " << target << "it has no Hit Points." << std::endl;
    else 
        std::cout << "ScavTrap " << Name << " can't attack " << target << "it has no energy Points." << std::endl;
}

void ScavTrap::takeDamage(unsigned int amount) {
    if (HitPoints > amount) 
        HitPoints -= amount;
    else if (HitPoints > 0)
        HitPoints = 0;
    else  {
        std::cout << "ScavTrap " << Name << " can't suffer damage it's Hit points are already 0." << std::endl;
        return;
    }  
    std::cout << "ScavTrap " << Name << " suffered " << amount << " points of damage" << std::endl;
        
}

void ScavTrap::beRepaired(unsigned int amount) {
    if (EnergyPoints > 0) {
        HitPoints += amount;
        EnergyPoints--;
        std::cout << "ScavTrap " << Name << " is repaired it's Hit Points are " <<  HitPoints << std::endl;
    }
    else    
        std::cout << "ScavTrap " << Name << " can't be repaired it's Energy Points are 0." << std::endl;
        
}

void ScavTrap::guardGate() {
    if (!Gate)
        Gate = true;
    else {
        std::cout << "ScavTrap " << Name << " is already guarding the gate." << std::endl;
        return;
    }
    std::cout << "ScavTrap " << Name << " now is guarding the gate." << std::endl;
    
}