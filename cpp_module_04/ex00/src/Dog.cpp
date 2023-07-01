/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tehuanmelo <tehuanmelo@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 15:07:51 by tehuanmelo        #+#    #+#             */
/*   Updated: 2023/07/01 16:30:24 by tehuanmelo       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Animal.hpp"
#include "../inc/Dog.hpp"

Dog::Dog() : Animal() {
    std::cout << GREEN << "Dog class: Default constructor called" << RESETCOLOR << std::endl;
    type = "Dog";
}

Dog::Dog(const Dog& copy) : Animal(copy) {
    std::cout << "Dog class: Copy constructor called" << std::endl;
    *this = copy;
}

Dog& Dog::operator=(const Dog& copy) {
    std::cout << GREEN << "Dog class: Copy assignment operator called" << RESETCOLOR << std::endl;
    if (this != &copy)
        type = copy.type;
    return *this;
}

Dog::~Dog() {
    std::cout << GREEN << "Dog class: Destructor called" << RESETCOLOR << std::endl;
}

void Dog::makeSound() const{
    std::cout << GREEN << "WOOF!! WOOF!!" << RESETCOLOR << std::endl;
}
