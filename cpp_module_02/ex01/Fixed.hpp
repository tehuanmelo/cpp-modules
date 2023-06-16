/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-melo <tde-melo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 21:46:02 by tehuanmelo        #+#    #+#             */
/*   Updated: 2023/06/16 18:07:02 by tde-melo         ###   ########.fr       */
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
        Fixed();
        Fixed(const int i);
        Fixed(const float f);
        Fixed(const Fixed& copy);
        Fixed &operator=(const Fixed& origin);
        ~Fixed();
        int getRawBits(void) const;
        void setRawBits(int const raw);
        float toFloat(void) const;
        int toInt(void) const;
};

#endif