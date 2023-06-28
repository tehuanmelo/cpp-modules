/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-melo <tde-melo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 21:46:02 by tehuanmelo        #+#    #+#             */
/*   Updated: 2023/06/27 10:06:42 by tde-melo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <string>
#include <cmath>

class Fixed {
    private:
        int Value;
        static const int Bits = 8;
    public:
        // Constructors
        Fixed();
        Fixed(const int i);
        Fixed(const float f);
        Fixed(const Fixed& copy);
        
        // Deconstructors
        ~Fixed();
        
        // Overloaded Operators

        // Assignment Operator
        Fixed& operator=(const Fixed& origin);
        
        // Arithmetic operators: +, -, *, and /.
        Fixed operator+(const Fixed& add);
        Fixed operator-(const Fixed& sub);
        Fixed operator*(const Fixed& mult);
        Fixed operator/(const Fixed& div);
        
        // Comparison operators: >, <, >=, <=, == and !=
        bool operator>(const Fixed& rOperand);
        bool operator<(const Fixed& rOperand);
        bool operator>=(const Fixed& rOperand);
        bool operator<=(const Fixed& rOperand);
        bool operator==(const Fixed& rOperand);
        bool operator!=(const Fixed& rOperand);
        
        // Increment/Decrement operators.
        Fixed& operator++(void);
        Fixed operator++(int);
        Fixed& operator--(void);
        Fixed operator--(int);

        // Methods
        
        // Min Max methods
        static Fixed& max(Fixed& a, Fixed& b);
        static Fixed& min(Fixed& a, Fixed& b);
        static const Fixed& max(const Fixed& a, const Fixed& b);
        static const Fixed& min(const Fixed& a, const Fixed& b);
        
        // toInt toFloat methods
        float toFloat(void) const;
        int toInt(void) const;
        
        // Getter
        int getRawBits(void) const;

        //Setter
        void setRawBits(int const raw);
};

// insertion orveload
std::ostream& operator<<(std::ostream& COUT, const Fixed& obj);

#endif