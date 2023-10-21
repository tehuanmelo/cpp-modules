/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tehuanmelo <tehuanmelo@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 18:57:26 by tehuanmelo        #+#    #+#             */
/*   Updated: 2023/10/21 22:17:56 by tehuanmelo       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <time.h>
#include "../inc/Span.hpp"



int main() {
    
    srand(time(NULL));

    // Constructors test
    int size = 20;
    std::cout << "Constructors and addNumbers() Test\n\n";
    Span a(size);
    for (int i = 0; i < size; i++)
        a.addNumber((rand() % 100) + 1);
    Span b(a), c;
    c = b;

    a.print();
    b.print();
    c.print();
    
    // Member functios test
    std::cout << "\nshortestSpan and longestSpan test\n\n";
    try
    {
        
        int size = 10;
        Span container(size);
        for (int i = 0; i < size; i++)
            container.addNumber((rand() % 100) + 1);
        // container.addNumber(5);
        container.print();
        std::cout << "shortest span: " << container.shortestSpan() << std::endl;
        std::cout << "longest span: " << container.longestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    
   
    
    return 0;
}