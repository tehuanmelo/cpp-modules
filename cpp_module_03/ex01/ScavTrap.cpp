/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-melo <tde-melo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 18:52:35 by tehuanmelo        #+#    #+#             */
/*   Updated: 2023/06/28 10:28:16 by tde-melo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
    std::cout << YELLOW <<  "ScavTrap constructor called" << RESET_COLOR << std::endl;
    HitPoints = 100;
    EnergyPoints = 50;
    AttackDamage = 20;
    Gate = false;
}

ScavTrap::ScavTrap(const ScavTrap& copy) : ClapTrap(copy) {
    Gate = copy.Gate;
    std::cout << YELLOW << "ScavTrap copy constructor called" << RESET_COLOR << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& copy) {
    std::cout << YELLOW << "ScavTrap copy assignment operator called" << RESET_COLOR << std::endl;
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
    std::cout << YELLOW << "ScavTrap " << Name << " destructor called" << RESET_COLOR << std::endl;
}

void ScavTrap::attack(const std::string &target) {
    if (HitPoints > 0 && EnergyPoints > 0) {
        EnergyPoints--;
        std::cout << YELLOW << "ScavTrap " << Name << " attacks " << target << ", causing " << AttackDamage << " points of damage!" << RESET_COLOR << std::endl;
    }
    else if (HitPoints == 0 )
        std::cout << YELLOW << "ScavTrap " << Name << " can't attack " << target << "it has no Hit Points." << RESET_COLOR << std::endl;
    else 
        std::cout << YELLOW << "ScavTrap " << Name << " can't attack " << target << "it has no energy Points." << RESET_COLOR << std::endl;
}

void ScavTrap::guardGate() {
    if (!Gate)
        Gate = true;
    else {
        std::cout << YELLOW << "ScavTrap " << Name << " is already guarding the gate." << RESET_COLOR << std::endl;
        return;
    }
    std::cout << YELLOW << "ScavTrap " << Name << " now is guarding the gate." << RESET_COLOR << std::endl;
    
}