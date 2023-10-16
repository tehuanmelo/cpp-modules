/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tehuanmelo <tehuanmelo@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 21:03:18 by tehuanmelo        #+#    #+#             */
/*   Updated: 2023/10/15 22:35:05 by tehuanmelo       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Array.hpp"

int main() {

    try
    {
        Array<int> a(3);
        Array<int> b(a);
        Array<int> c(5);

        std::cout << a.getSize() << std::endl;
        std::cout << b.getSize() << std::endl;
        std::cout << c.getSize() << std::endl;

        c = b;
        std::cout << c.getSize() << std::endl;

        a.printArrayAddress();
        b.printArrayAddress();
        c.printArrayAddress();

        a.setIndex(10, 5);
        a.setIndex(2, 23);
        
        a.printArray();
        b.printArray();
        c.printArray();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    

    

    return 0;
}