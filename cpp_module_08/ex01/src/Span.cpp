/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tehuanmelo <tehuanmelo@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 21:34:28 by tehuanmelo        #+#    #+#             */
/*   Updated: 2023/10/21 22:07:05 by tehuanmelo       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Span.hpp"

Span::Span() : Size(0) {}

Span::Span(unsigned int n) : Size(n) {}

Span::Span(Span& copy) 
{
    *this = copy;
}

Span& Span::operator=(Span& copy) 
{
    if (this == &copy)
        return *this;
    std::vector<int>::iterator it = copy.container.begin();
    for (; it != copy.container.end(); ++it)
        this->container.push_back(*it);
    return *this;
}

Span::~Span() {}

void Span::addNumber(int num)
{
    if (container.size() == Size)
        throw std::runtime_error("Container is full.");
    container.push_back(num);
}

int Span::shortestSpan()
{
    if (container.empty() || container.size() == 1)
        throw std::runtime_error("Can't find the shortest span");
    std::sort(container.begin(), container.end());
    return container[1] - container[0];
}

int Span::longestSpan()
{
    if (container.empty() || container.size() == 1)
        throw std::runtime_error("Can't find the shortest span");
    std::sort(container.begin(), container.end());
    return container[container.size() - 1] - container[0];
}

void Span::print()
{
    if (container.empty())
        return;
    for (std::vector<int>::iterator it = container.begin(); it != container.end(); ++it)
        std::cout << *it << " "; 
    std::cout << std::endl;
}