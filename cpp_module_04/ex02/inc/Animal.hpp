/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tehuanmelo <tehuanmelo@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 15:07:51 by tehuanmelo        #+#    #+#             */
/*   Updated: 2023/07/13 15:18:58 by tehuanmelo       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string.h>

#define YELLOW "\033[33m"
#define GREEN "\033[32m"
#define MAGENTA "\033[35m"
#define RESETCOLOR "\033[0m"

class Animal
{
protected:
    std::string type;
public:
    Animal();
    Animal(const Animal& copy);
    Animal& operator=(const Animal& copy);
    virtual ~Animal();
    virtual void makeSound() const = 0; 
    std::string getType() const;
};

#endif