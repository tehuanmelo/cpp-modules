/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-melo <tde-melo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 22:10:34 by tehuanmelo        #+#    #+#             */
/*   Updated: 2023/06/16 18:22:28 by tde-melo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main()
{
    Fixed a;
    Fixed const b( 10 ); 
    Fixed const c( 42.42f );
    Fixed const d( b );
    a = Fixed( 1234.4321f );

    std::cout << "a is " << a.toInt() << " as integer" << std::endl; 
    std::cout << "b is " << b.toInt() << " as integer" << std::endl; 
    std::cout << "c is " << c.toInt() << " as integer" << std::endl; 
    std::cout << "d is " << d.toInt() << " as integer" << std::endl;
}