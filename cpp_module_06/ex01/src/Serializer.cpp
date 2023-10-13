/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tehuanmelo <tehuanmelo@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 13:21:11 by tehuanmelo        #+#    #+#             */
/*   Updated: 2023/10/12 13:32:00 by tehuanmelo       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Serializer.hpp"

// PRIVATE MEMBERS

Serializer::Serializer() {}

Serializer::Serializer(const Serializer& copy) { 
    (void)copy; 
}

Serializer& Serializer::operator=(const Serializer& copy) {
    (void)copy;
    return *this;
}

// PUBLIC MEMBERS

Serializer::~Serializer() {}

uintptr_t Serializer::serialize(Data* ptr) {
    return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw) {
    return reinterpret_cast<Data*>(raw);
}