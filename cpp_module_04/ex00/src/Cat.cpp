/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tehuanmelo <tehuanmelo@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 15:07:51 by tehuanmelo        #+#    #+#             */
/*   Updated: 2023/07/01 16:31:00 by tehuanmelo       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Animal.hpp"
#include "../inc/Cat.hpp"

Cat::Cat() : Animal() {
    std::cout << YELLOW << "Cat class: Default constructor called" << RESETCOLOR << std::endl;
    type = "Cat";
}

Cat::Cat(const Cat& copy) : Animal(copy) {
    std::cout << YELLOW << "Cat class: Copy constructor called" << RESETCOLOR << std::endl;
    *this = copy;
}

Cat& Cat::operator=(const Cat& copy) {
    std::cout << YELLOW << "Cat class: Copy assignment operator called" << RESETCOLOR << std::endl;
    if (this != &copy)
        type = copy.type;
    return *this;
}

Cat::~Cat() {
    std::cout << YELLOW << "Cat class: Destructor called" << RESETCOLOR << std::endl;
}

void Cat::makeSound() const {
    std::cout << YELLOW << "MEOW!! MEOW!!" << RESETCOLOR << std::endl;
}
