/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-melo <tde-melo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 01:48:50 by tehuanmelo        #+#    #+#             */
/*   Updated: 2023/10/22 17:39:28 by tde-melo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>

template <typename T>
class MutantStack : public std::stack<T>
{
private:
public:
    class iterator
    {
    private:
        typename MutantStack::container_type::iterator it;

    public:
        iterator(){};
        iterator(typename MutantStack::container_type::iterator it) : it(it) {}
        iterator(const iterator &copy) { *this = copy; }
        ~iterator() {}
        iterator &operator=(const iterator &copy)
        {
            if (this == &copy)
                return *this;
            this->it = copy.it;
            return *this;
        }
        bool operator!=(iterator &other)
        {
            return this->it != other.it;
        }
        bool operator==(iterator &other)
        {
            return this->it == other.it;
        }
        T &operator*()
        {
            return *it;
        }
        iterator &operator++()
        {
            ++(this->it);
            return *this;
        }
        iterator operator++(int)
        {
            iterator tmp = *this;
            ++(this->it);
            return tmp;
        }
        iterator &operator--()
        {
            --(this->it);
            return *this;
        }
        iterator operator--(int)
        {
            iterator tmp = *this;
            --(this->it);
            return tmp;
        }
    };

    iterator begin()
    {
        return iterator(this->c.begin());
    }

    iterator end()
    {
        return iterator(this->c.end());
    }
};


#endif