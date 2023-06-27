/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tehuanmelo <tehuanmelo@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 15:20:58 by tehuanmelo        #+#    #+#             */
/*   Updated: 2023/06/27 22:56:17 by tehuanmelo       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    std::cout << "FragTrap constructor called" << std::endl;
    HitPoints = 100;
    EnergyPoints = 100;
    AttackDamage = 30;
}

FragTrap::FragTrap(const FragTrap &copy) : ClapTrap(copy)
{
    std::cout << "FragTrap copy construtor called" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &copy)
{
    std::cout << "FragTrap copy assignment operator called" << std::endl;
    if (this != &copy)
    {
        Name = copy.Name;
        HitPoints = copy.HitPoints;
        EnergyPoints = copy.EnergyPoints;
        AttackDamage = copy.AttackDamage;
    }
    return *this;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap " << Name << " destructor called" << std::endl;
}

void FragTrap::attack(const std::string &target) {
    if (HitPoints > 0 && EnergyPoints > 0) {
        EnergyPoints--;
        std::cout << "FragTrap " << Name << " attacks " << target << ", causing " << AttackDamage << " points of damage!" << std::endl;
    }
    else if (HitPoints == 0 )
        std::cout << "FragTrap " << Name << " can't attack " << target << "it has no Hit Points." << std::endl;
    else 
        std::cout << "FragTrap " << Name << " can't attack " << target << "it has no energy Points." << std::endl;
}

void FragTrap::takeDamage(unsigned int amount)
{
    if (HitPoints > amount)
        HitPoints -= amount;
    else if (HitPoints > 0)
        HitPoints = 0;
    else
    {
        std::cout << "FragTrap " << Name << " can't suffer damage it's Hit points are already 0." << std::endl;
        return;
    }
    std::cout << "FragTrap " << Name << " suffered " << amount << " points of damage" << std::endl;
}

void FragTrap::beRepaired(unsigned int amount)
{
    if (EnergyPoints > 0)
    {
        HitPoints += amount;
        EnergyPoints--;
        std::cout << "FragTrap " << Name << " is repaired it's Hit Points are " << HitPoints << std::endl;
    }
    else
        std::cout << "FragTrap " << Name << " can't be repaired it's Energy Points are 0." << std::endl;
}

void FragTrap::highFivesGuys(void)
{
    std::cout << "FragTrap " << Name << ": Want a highfive?" << std::endl;
    std::cout << "      _" << std::endl;
    std::cout << "  _  / |" << std::endl;
    std::cout << " / \\ | | /\\" << std::endl; 
    std::cout << "  \\ \\| |/ /" << std::endl;
    std::cout << "   \\ Y | /___" << std::endl;
    std::cout << " .-.) '. `__/" << std::endl;
    std::cout << "(.-.   / /" << std::endl;
    std::cout << "    | ' |" << std::endl;
    std::cout << "    |___|" << std::endl;
    std::cout << "   [_____]" << std::endl;
}