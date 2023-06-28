/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tehuanmelo <tehuanmelo@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 15:20:58 by tehuanmelo        #+#    #+#             */
/*   Updated: 2023/06/28 08:53:57 by tehuanmelo       ###   ########.fr       */
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
    *this = copy;
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

void FragTrap::highFiveGuys(void)
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