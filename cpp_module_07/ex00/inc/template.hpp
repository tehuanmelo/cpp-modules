/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   template.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tehuanmelo <tehuanmelo@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 20:01:10 by tehuanmelo        #+#    #+#             */
/*   Updated: 2023/10/15 20:02:00 by tehuanmelo       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEMPLATE_HPP
#define TEMPLATE_HPP

#include <iostream>
#include <string>

template<typename T>
void swap(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}

template<typename T>
T max(T& a, T& b) {
    if (a > b)
        return a;
    else if (a < b)
        return b;
    return b;
}

template<typename T>
T min(T& a, T& b) {
    if (a < b)
        return a;
    else if (a > b)
        return b;
    return b;
}

#endif