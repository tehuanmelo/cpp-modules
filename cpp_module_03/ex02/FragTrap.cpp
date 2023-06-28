/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-melo <tde-melo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 15:20:58 by tehuanmelo        #+#    #+#             */
/*   Updated: 2023/06/28 11:24:12 by tde-melo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    std::cout << GREEN << "FragTrap constructor called" << RESET_COLOR << std::endl;
    HitPoints = 100;
    EnergyPoints = 100;
    AttackDamage = 30;
}

FragTrap::FragTrap(const FragTrap &copy) : ClapTrap(copy)
{
    std::cout << GREEN << "FragTrap copy construtor called" << RESET_COLOR << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &copy)
{
    std::cout << GREEN << "FragTrap copy assignment operator called" << RESET_COLOR << std::endl;
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
    std::cout << GREEN << "FragTrap " << Name << " destructor called" << RESET_COLOR << std::endl;
}

void FragTrap::highFiveGuys(void)
{
    std::cout << GREEN << "FragTrap " << Name << ": Highfive?" << std::endl;
    std::cout << "      _" << std::endl;
    std::cout << "  _  / |" << std::endl;
    std::cout << " / \\ | | /\\" << std::endl; 
    std::cout << "  \\ \\| |/ /" << std::endl;
    std::cout << "   \\ Y | /___" << std::endl;
    std::cout << " .-.) '. `__/" << std::endl;
    std::cout << "(.-.   / /" << std::endl;
    std::cout << "    | ' |" << std::endl;
    std::cout << "    |___|" << std::endl;
    std::cout << "   [_____]" << RESET_COLOR << std::endl;
}