/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tehuanmelo <tehuanmelo@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 18:52:24 by tehuanmelo        #+#    #+#             */
/*   Updated: 2023/11/20 22:05:44 by tehuanmelo       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <list>
#include <climits>
#include <time.h>

class Span
{
private:
    std::vector<unsigned int> container;
    unsigned int Size;

public:
    Span();
    Span(unsigned int n);
    Span(Span &copy);
    Span &operator=(Span& copy);
    ~Span();

    void addNumber(int num);
    void addNumber(unsigned int min, unsigned int max);
    int shortestSpan();
    int longestSpan();
    void print();
};

#endif