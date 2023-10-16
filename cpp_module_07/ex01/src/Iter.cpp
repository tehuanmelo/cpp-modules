/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iter.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tehuanmelo <tehuanmelo@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 20:01:10 by tehuanmelo        #+#    #+#             */
/*   Updated: 2023/10/15 20:47:15 by tehuanmelo       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Iter.hpp"

void increment(int& num) {
    num++;
}

void decrement(int& num) {
    num--;
}

void print(int a) {
    std::cout << a << " ";
}