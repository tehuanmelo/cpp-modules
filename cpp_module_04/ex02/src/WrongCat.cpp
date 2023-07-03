/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tehuanmelo <tehuanmelo@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 12:53:47 by tehuanmelo        #+#    #+#             */
/*   Updated: 2023/07/02 13:08:46 by tehuanmelo       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/WrongAnimal.hpp"
#include "../inc/WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal() {
    std::cout << RED << "WrongCat class: Default constructor called" << RESETCOLOR << std::endl;
    type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat& copy) : WrongAnimal(copy) {
    std::cout << RED << "WrongCat class: Copy constructor called" << RESETCOLOR << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& copy) {
    std::cout << RED << "WrongCat class: Copy assignment operator called" << RESETCOLOR << std::endl;
    if (this != &copy)
        type = copy.type;
    return *this;
}

WrongCat::~WrongCat() {
    std::cout << RED << "WrongCat class: Destructor called" << RESETCOLOR << std::endl;
}

void WrongCat::makeSound() const {
    std::cout << RED << "Wrong cat noise" << RESETCOLOR << std::endl;
}
