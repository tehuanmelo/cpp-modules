/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-melo <tde-melo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 13:10:04 by tehuanmelo        #+#    #+#             */
/*   Updated: 2023/10/13 20:07:48 by tde-melo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Serializer.hpp"

int main() {
    
    Data originalData;
    originalData.value = 42;

    
    Data* ptr = &originalData;
    uintptr_t uintPtr;

    uintPtr = Serializer::serialize(ptr);
    
    std::cout << "Integer representation of ptr: "  << uintPtr << std::endl;

    Data* ptr2 = Serializer::deserialize(uintPtr);

    std::cout << "Address of ptr: " << ptr << std::endl;
    std::cout << "Address of ptr2: "  << ptr2 << std::endl;
    std::cout << "Content of ptr: "  << ptr->value << std::endl;
    std::cout << "Content of ptr2: "  << ptr2->value << std::endl;
}