/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tehuanmelo <tehuanmelo@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 21:34:28 by tehuanmelo        #+#    #+#             */
/*   Updated: 2024/07/22 14:12:12 by tehuanmelo       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Span.hpp"

Span::Span() : Size(0) {}

Span::Span(unsigned int n) : Size(n) {}

Span::Span(Span &copy)
{
    *this = copy;
}

Span &Span::operator=(Span &copy)
{
    if (this == &copy)
        return *this;
    std::vector<unsigned int>::iterator it = copy.container.begin();
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

void Span::addNumber(unsigned int min, unsigned int max)
{
    srand(time(NULL));
    if (container.size() == Size)
        throw std::runtime_error("Container is full.");
    while (container.size() != Size)
        container.push_back(rand() % (max - min + 1) + min);
}

int Span::shortestSpan()
{
    if (container.empty() || container.size() == 1)
        throw std::runtime_error("Can't find the shortest span");
    std::vector<unsigned int> dst(Size);
    std::copy(container.begin(), container.end(), dst.begin());
    std::sort(dst.begin(), dst.end());
    unsigned int shortSpan = UINT_MAX;
    std::vector<unsigned int>::iterator it = dst.begin();
    std::vector<unsigned int>::iterator next = dst.begin() + 1;
    while (next != dst.end())
    {
        if (*next >= *it && (*next - *it) < shortSpan)
            shortSpan = *next - *it;
        it++;
        next++;
    }
    return shortSpan;
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
    for (std::vector<unsigned int>::iterator it = container.begin(); it != container.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
}