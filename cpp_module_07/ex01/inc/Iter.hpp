/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tehuanmelo <tehuanmelo@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 20:01:10 by tehuanmelo        #+#    #+#             */
/*   Updated: 2023/10/15 20:44:45 by tehuanmelo       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>
#include <string>

template<typename T, typename F>
void iter(T& a, int len, F func) {
    for (int i = 0; i < len; i++) {
        func(a[i]);
    }
}

void increment(int& num);
void decrement(int& num);
void print(int a);

#endif