/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tehuanmelo <tehuanmelo@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 21:00:16 by tehuanmelo        #+#    #+#             */
/*   Updated: 2023/10/15 22:23:18 by tehuanmelo       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <string>

template<typename T>
class Array
{
private:
    T* array;
    unsigned int arraySize;
public:
    Array();
    Array(unsigned int size);
    Array(const Array& copy);
    Array& operator=(const Array& copy);
    ~Array();
    
    int getSize() const;
    void setIndex(unsigned int index, T value);
    
    void printArrayAddress() const;
    void printArray() const;

    T& operator[](unsigned int index);
};

#include "../src/Array.tpp"

#endif