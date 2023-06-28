/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-melo <tde-melo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 18:52:49 by tehuanmelo        #+#    #+#             */
/*   Updated: 2023/06/28 10:24:13 by tde-melo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

#define YELLOW "\033[33m"
#define RESET_COLOR "\033[39m"

class ScavTrap : public ClapTrap
{
private:
    bool Gate;
public:
    ScavTrap(std::string name);
    ScavTrap(const ScavTrap& copy);
    ScavTrap& operator=(const ScavTrap& copy);
    ~ScavTrap();
    void attack(const std::string &target);
    void guardGate();
};

#endif