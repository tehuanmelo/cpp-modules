/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tehuanmelo <tehuanmelo@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 13:09:37 by tehuanmelo        #+#    #+#             */
/*   Updated: 2023/07/02 13:18:46 by tehuanmelo       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/WrongAnimal.hpp"

WrongAnimal::WrongAnimal() {
    std::cout << BLUE << "WrongAnimal class: Defautl constructor called" << RESETCOLOR << std::endl;
    type = "Unknown wrong animal";
}

WrongAnimal::WrongAnimal(const WrongAnimal& copy) {
    std::cout << BLUE << "WrongAnimal class: Copy constructor called" << RESETCOLOR << std::endl;
    *this = copy;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& copy) {
    std::cout << BLUE << "WrongAnimal class: Copy assignment operator called" << RESETCOLOR << std::endl;
    if (this != &copy)
        type = copy.type;
    return *this;
}

WrongAnimal::~WrongAnimal() {
    std::cout << BLUE << "WrongAnimal class: Destructor called" << RESETCOLOR << std::endl;
}

void WrongAnimal::makeSound() const {
    std::cout << BLUE << "Unknown wrong animal sound" << RESETCOLOR << std::endl;
}

std::string WrongAnimal::getType() const {
    return type;
}
