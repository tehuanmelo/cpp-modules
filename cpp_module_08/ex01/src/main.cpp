/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tehuanmelo <tehuanmelo@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 18:57:26 by tehuanmelo        #+#    #+#             */
/*   Updated: 2024/07/22 19:03:46 by tehuanmelo       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Span.hpp"

int main()
{

    // Constructors test 
    std::cout << "Constructors and addNumbers() Test\n\n";
    int size = 20;
    Span a(size);
    a.addNumber(3);
    a.addNumber(5);
    a.addNumber(100, 500);
    Span b(a), c;
    c = b;

    a.print();
    b.print();
    c.print();

    // Member functios test
    std::cout << "\nshortestSpan and longestSpan test\n\n";
    try
    {

        int size = 5;
        Span container(size);
        container.addNumber(1, 50);
        container.print();
        std::cout << "shortest span: " << container.shortestSpan() << std::endl;
        std::cout << "longest span: " << container.longestSpan() << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    return 0;
}