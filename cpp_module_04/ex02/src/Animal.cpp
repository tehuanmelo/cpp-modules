/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tehuanmelo <tehuanmelo@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 15:07:51 by tehuanmelo        #+#    #+#             */
/*   Updated: 2023/07/03 15:11:19 by tehuanmelo       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Animal.hpp"

Animal::Animal() {
    std::cout << "Animal class: Default constructor called" << std::endl;
    type = "Unknown animal";
}

Animal::Animal(const Animal& copy) {
    std::cout << "Animal class: Copy constructor called" << std::endl;
    *this = copy;
}

Animal& Animal::operator=(const Animal& copy) {
    std::cout << "Animal class: Copy assignment operator called" << std::endl;
    if (this != &copy)
        type = copy.type;
    return *this;
}

Animal::~Animal() {
    std::cout << "Animal class: Destructor called" << std::endl;
}

// void Animal::makeSound() const {
//     std::cout << "Unknown animal sound" << std::endl;
// }

std::string Animal::getType() const {
    return type;
}
