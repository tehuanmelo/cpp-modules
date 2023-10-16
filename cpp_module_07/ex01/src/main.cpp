/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-melo <tde-melo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 18:02:52 by tehuanmelo        #+#    #+#             */
/*   Updated: 2023/10/16 19:44:16 by tde-melo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Iter.hpp"

int main( void ) { 
    
    int a[] = {1, 2, 3};
    
    iter(a, 3, print);
    std::cout << std::endl;
    
    iter(a, 3, increment);
    iter(a, 3, print);
    std::cout << std::endl;
    
    iter(a, 3, decrement);
    iter(a, 3, print);
    std::cout << std::endl;
    
    iter(a, 10, print);
    std::cout << std::endl;

    
    
    return 0; 
}
