/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tehuanmelo <tehuanmelo@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 21:52:45 by tehuanmelo        #+#    #+#             */
/*   Updated: 2023/06/18 16:01:02 by tehuanmelo       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// Default constructor that initializes the fixed-point number value to 0.
Fixed::Fixed() : Value(0) {}

// A constructor that takes a constant integer as a parameter.
// It converts it to the corresponding fixed-point value.
Fixed::Fixed(const int i) {
    Value = i * (1 << Bits);
}

// A constructor that takes a constant floating-point number as a parameter.
// It converts it to the corresponding fixed-point value.
Fixed::Fixed(const float f) {
    Value = roundf(f * (1 << Bits));
}

// Copy constructor
Fixed::Fixed(const Fixed &copy) {
    Value = copy.Value;
}

// Destructor
Fixed::~Fixed() {}

// Copy assignment operator overload.
Fixed& Fixed::operator=(const Fixed &origin) {
    if (this != &origin) 
        Value = origin.Value;
    return *this;
}

// The 4 arithmetic operators: +, -, *, and /.

Fixed Fixed::operator+(const Fixed &add) {
    Fixed result;
    result.Value = this->Value + add.Value;
    return result;
}

Fixed Fixed::operator-(const Fixed &sub) {
    Fixed result;
    result.Value = this->Value - sub.Value;
    return result;
}

Fixed Fixed::operator*(const Fixed &mult) {
    Fixed result;
    result.Value = this->Value * (mult.Value >> Bits);
    return result;
}

Fixed Fixed::operator/(const Fixed &div) {
    Fixed result;
    result.Value = this->Value / (div.Value >> Bits);
    return result;
}

// The 6 comparison operators: >, <, >=, <=, == and !=

bool Fixed::operator>(const Fixed& rOperand) {
    if (Value > rOperand.Value)
        return true;
    return false;
}

bool Fixed::operator<(const Fixed& rOperand) {
    if (Value < rOperand.Value)
        return true;
    return false;
}

bool Fixed::operator>=(const Fixed& rOperand) {
    if (Value >= rOperand.Value)
        return true;
    return false;
}

bool Fixed::operator<=(const Fixed& rOperand) {
    if (Value <= rOperand.Value)
        return true;
    return false;
}

bool Fixed::operator==(const Fixed& rOperand) {
    if (Value == rOperand.Value)
        return true;
    return false;
}

bool Fixed::operator!=(const Fixed& rOperand) {
    if (Value != rOperand.Value)
        return true;
    return false;
}

// The 4 increment/decrement operators.

Fixed& Fixed::operator++(void) {
    Value++;
    return *this;
}

Fixed Fixed::operator++(int) {
    Fixed tmp;
    tmp.Value = Value;
    Value++;
    return tmp;
}

Fixed& Fixed::operator--(void) {
    Value--;
    return *this;
}

Fixed Fixed::operator--(int) {
    Fixed tmp;
    tmp.Value = Value;
    Value--;
    return tmp;
}

// Min and Max functions 

Fixed& Fixed::max(Fixed& a, Fixed& b) {
    return (a > b) ? a : b;
}

Fixed& Fixed::min(Fixed& a, Fixed& b) {
    return (a < b) ? a : b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
    return (a.Value > b.Value) ? a : b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
    return (a.Value < b.Value) ? a : b;
}

// Getter
int Fixed::getRawBits(void) const {
    return Value;
}

// Setter
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

// An overload of the insertion («) operator that inserts a floating-point representation
// of the fixed-point number into the output stream object passed as parameter.
std::ostream& operator<<(std::ostream& COUT, const Fixed& obj) {
    return (COUT << obj.toFloat());
}