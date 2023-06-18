/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tehuanmelo <tehuanmelo@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 22:10:34 by tehuanmelo        #+#    #+#             */
/*   Updated: 2023/06/18 16:03:36 by tehuanmelo       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main()
{
    Fixed a;
    Fixed const b(Fixed(5.05f) * Fixed(2));
    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << Fixed::max(a, b) << std::endl;

    // Fixed a(10);
    // Fixed b(5);
    // std::cout << "a = " << a << std::endl;
    // std::cout << "b = " << b << std::endl;
    // if (a > b)
    //     std::cout << "a is bigger than b" << std::endl;
    // else if (a < b)
    //     std::cout << "a is less than b" << std::endl;
    // else if (a == b)
    //     std::cout << "a is equals b" << std::endl;
    // std::cout << "a + b = " << a + b << std::endl;
    // std::cout << "a - b = " << a - b << std::endl;
    // std::cout << "a * b = " << a * b << std::endl;
    // std::cout << "a / b = " << a / b << std::endl;
    // std::cout << "++a = " << ++a << std::endl;
    // std::cout << "a++ = " << a++ << std::endl;
    // std::cout << "--a = " << --a << std::endl;
    // std::cout << "a-- = " << a-- << std::endl;

    return 0;
}