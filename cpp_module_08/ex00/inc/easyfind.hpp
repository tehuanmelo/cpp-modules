/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tehuanmelo <tehuanmelo@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 19:24:50 by tehuanmelo        #+#    #+#             */
/*   Updated: 2023/10/19 17:56:13 by tehuanmelo       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

template<typename T>
typename T::iterator easyfind(T& array, int value) {
    typename T::iterator it = std::find(array.begin(), array.end(), value);
    if (it != array.end())
        return it;
    throw std::out_of_range("Could not find the element");
}

#endif