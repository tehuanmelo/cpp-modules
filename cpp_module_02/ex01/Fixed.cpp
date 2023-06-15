/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-melo <tde-melo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 21:52:45 by tehuanmelo        #+#    #+#             */
/*   Updated: 2023/06/15 18:00:30 by tde-melo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() {
    std::cout << "Default constructor called" << std::endl;
    Value = 0;
}

Fixed::Fixed(const int& a) {
    std::cout << "Default constructor called" << std::endl;
    Value = a;
}

Fixed::Fixed(const Fixed &origin) {
    std::cout << "Copy constructor called" << std::endl;
    Value = origin.Value;
}

Fixed& Fixed::operator=(const Fixed &origin) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &origin) 
        Value = origin.Value;
    return *this;
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
    
}

int Fixed::getRawBits(void) const {
    std::cout << "getRawBits member function called" << std::endl;
    return Value;
}

void Fixed::setRawBits(int const raw) {
    Value = raw;
}