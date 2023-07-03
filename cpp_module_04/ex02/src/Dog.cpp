/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tehuanmelo <tehuanmelo@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 15:07:51 by tehuanmelo        #+#    #+#             */
/*   Updated: 2023/07/02 19:27:35 by tehuanmelo       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Animal.hpp"
#include "../inc/Dog.hpp"

Dog::Dog() : Animal() {
    std::cout << GREEN << "Dog class: Default constructor called" << RESETCOLOR << std::endl;
    type = "Dog";
    brain = new Brain();
}

Dog::Dog(const Dog& copy) : Animal(copy) {
    std::cout << "Dog class: Copy constructor called" << std::endl;
    *this = copy;
}

Dog& Dog::operator=(const Dog& copy) {
    std::cout << GREEN << "Dog class: Copy assignment operator called" << RESETCOLOR << std::endl;
    if (this != &copy) {
        type = copy.type;
        brain = new Brain();
        if (!brain) {
            std::cout << GREEN << "Memory Allocation failed" << RESETCOLOR << std::endl;
            exit(1);
        }
        *this->brain = *copy.brain;
    }
    return *this;
}

Dog::~Dog() {
    std::cout << GREEN << "Dog class: Destructor called" << RESETCOLOR << std::endl;
    delete brain;
}

void Dog::makeSound() const{
    std::cout << GREEN << "WOOF!! WOOF!!" << RESETCOLOR << std::endl;
}

void Dog::setIdeas(int i, std::string idea) const {
    if (i < 100)
        brain->setIdeas(i, idea);
    else    
        std::cout << GREEN << "Only 100 ideas per brain..." << RESETCOLOR << std::endl;
}

std::string Dog::getIdea(int i) const {
    if (i < 100)
        return brain->getIdea(i);
    else
        std::cout << GREEN << "Only 100 ideas per brain..." << RESETCOLOR << std::endl;
    return NULL;
}
