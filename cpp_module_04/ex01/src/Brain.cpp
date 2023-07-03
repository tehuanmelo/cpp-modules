/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tehuanmelo <tehuanmelo@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 15:07:51 by tehuanmelo        #+#    #+#             */
/*   Updated: 2023/07/01 16:29:40 by tehuanmelo       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Brain.hpp"

Brain::Brain() {
    std::cout << MAGENTA "Brain class: Default constructor called" RESETCOLOR << std::endl;
    for (int i = 0; i < 100; i++)
        ideas[i] = "No idea";
}

Brain::Brain(const Brain& copy) {
    std::cout << MAGENTA << "Brain class: Copy constructor called" << RESETCOLOR << std::endl;
    *this = copy;
}

Brain& Brain::operator=(const Brain& copy) {
    std::cout << MAGENTA "Brain class: Copy assignment operator called" RESETCOLOR << std::endl;
    if (this != &copy)
        for (int i = 0; i < 100; i++)
            this->ideas[i] = copy.ideas[i];
    return *this;
}

Brain::~Brain() {
    std::cout << MAGENTA "Brain class: Destructor called" RESETCOLOR << std::endl;
}

void Brain::setIdeas(int i, std::string idea) {
    if (i < 100)
        ideas[i] = idea;
    else    
        std::cout << MAGENTA "Only 100 ideas per brain..." RESETCOLOR << std::endl;
}

std::string Brain::getIdea(int i) const {
    if (i < 100)
        return ideas[i];
    else
        std::cout << MAGENTA "Only 100 ideas per brain..." RESETCOLOR << std::endl;
    return NULL;
}
