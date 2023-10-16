/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-melo <tde-melo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 20:01:10 by tehuanmelo        #+#    #+#             */
/*   Updated: 2023/10/16 19:43:19 by tde-melo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>
#include <string>

template<typename T, typename F>
void iter(T& a, size_t len, F func) {
    if (len > (sizeof(a) / sizeof(a[0]))) {
        std::cerr << "Length error" << std::endl;
        return;
    }
    for (size_t i = 0; i < len; i++) {
        func(a[i]);
    }
}

void increment(int& num);
void decrement(int& num);
void print(int a);

#endif