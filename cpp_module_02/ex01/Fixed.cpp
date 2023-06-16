/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-melo <tde-melo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 21:52:45 by tehuanmelo        #+#    #+#             */
/*   Updated: 2023/06/16 18:21:36 by tde-melo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() {
    std::cout << "Default constructor called" << std::endl;
    Value = 0;
}

// A constructor that takes a constant integer as a parameter.
// It converts it to the corresponding fixed-point value.
Fixed::Fixed(const int i) {
    std::cout << "Int constructor called" << std::endl;
    Value = (i << Bits);
}

// A constructor that takes a constant floating-point number as a parameter.
// It converts it to the corresponding fixed-point value.
Fixed::Fixed(const float f) {
    std::cout << "Float constructor called" << std::endl;
    Value = f * roundf(1 << Bits);
}

Fixed::Fixed(const Fixed &copy) {
    std::cout << "Copy constructor called" << std::endl;
    Value = copy.Value;
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

// converts the fixed-point value to a floating-point value.
float Fixed::toFloat(void) const {
    return (float)Value / (float)(1 << Bits);
}

// converts the fixed-point value to an integer value.
int Fixed::toInt(void) const {
    return (Value >> Bits);
}