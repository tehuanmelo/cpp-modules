/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-melo <tde-melo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 21:46:02 by tehuanmelo        #+#    #+#             */
/*   Updated: 2023/06/15 18:02:49 by tde-melo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <string>

class Fixed {
    private:
        int Value;
        static const int Bits = 8;
    public:
        Fixed();
        Fixed(const int& a);
        Fixed(const Fixed& origin);
        Fixed &operator=(const Fixed& origin);
        ~Fixed();
        int getRawBits(void) const;
        void setRawBits(int const raw);
};

#endif