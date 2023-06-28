/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-melo <tde-melo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 15:16:48 by tehuanmelo        #+#    #+#             */
/*   Updated: 2023/06/28 10:33:39 by tde-melo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

#define GREEN "\033[32m"
#define RESET_COLOR "\033[39m"

class FragTrap : public ClapTrap
{
private:
    /* data */
public:
    FragTrap(std::string name);
    FragTrap(const FragTrap& copy);
    FragTrap& operator=(const FragTrap& copy);
    ~FragTrap();
    // void attack(const std::string &target);
    // void takeDamage(unsigned int amount);
    // void beRepaired(unsigned int amount);
    void highFiveGuys(void);
};

#endif