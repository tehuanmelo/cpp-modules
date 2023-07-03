/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tehuanmelo <tehuanmelo@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 15:07:51 by tehuanmelo        #+#    #+#             */
/*   Updated: 2023/07/03 20:39:06 by tehuanmelo       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Animal.hpp"
#include "../inc/Cat.hpp"

Cat::Cat() : Animal() {
    std::cout << YELLOW << "Cat class: Default constructor called" << RESETCOLOR << std::endl;
    type = "Cat";
    brain = new Brain();
}

Cat::Cat(const Cat& copy) : Animal(copy) {
    std::cout << "Cat class: Copy constructor called" << std::endl;
    brain = new Brain();
    *this = copy;
}

Cat& Cat::operator=(const Cat& copy) {
    std::cout << YELLOW << "Cat class: Copy assignment operator called" << RESETCOLOR << std::endl;
    if (this != &copy) {
        type = copy.type;
        *this->brain = *copy.brain;
    }
    return *this;
}

Cat::~Cat() {
    std::cout << YELLOW << "Cat class: Destructor called" << RESETCOLOR << std::endl;
    delete brain;
}

void Cat::makeSound() const{
    std::cout << YELLOW << "MEOW!! MEOW!!" << RESETCOLOR << std::endl;
}

void Cat::setIdeas(int i, std::string idea) const {
    if (i < 100)
        brain->setIdeas(i, idea);
    else    
        std::cout << YELLOW << "Only 100 ideas per brain..." << RESETCOLOR << std::endl;
}

std::string Cat::getIdea(int i) const {
    if (i < 100)
        return brain->getIdea(i);
    else
        std::cout << YELLOW << "Only 100 ideas per brain..." << RESETCOLOR << std::endl;
    return NULL;
}
