/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tehuanmelo <tehuanmelo@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 23:21:05 by tehuanmelo        #+#    #+#             */
/*   Updated: 2023/06/09 23:24:39 by tehuanmelo       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_H
#define WEAPON_H

#include <iostream>

class Weapon
{
private:
    std::string type;
public:
    Weapon();
    Weapon(std::string type);
    void setType(std::string type);
    std::string getType();
    ~Weapon();
};

#endif