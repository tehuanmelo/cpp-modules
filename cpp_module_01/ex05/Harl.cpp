/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tehuanmelo <tehuanmelo@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 15:05:35 by tehuanmelo        #+#    #+#             */
/*   Updated: 2023/06/11 13:59:03 by tehuanmelo       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void Harl::debug() {
	std::cout
		<< "[ DEBUG ]" << std::endl
		<< "I love to get extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger."
		<< " I just love it!"
		<< std::endl;
}

void Harl::info() {
	std::cout
		<< "[ INFO ]" << std::endl
		<< "I cannot believe adding extra bacon cost more money."
		<< " You don’t put enough!"
		<< " If you did I would not have to ask for it!"
		<< std::endl;
}

void Harl::warning() {
	std::cout
		<< "[ WARNING ]" << std::endl
		<< "I think I deserve to have some extra bacon for free."
		<< " I’ve been coming here for years and you just started working here last month."
		<< std::endl;
}

void Harl::error() {
	std::cout
		<< "[ ERROR ]" << std::endl
		<< "This is unacceptable, I want to speak to the manager now."
		<< std::endl;
}

Harl::Harl() {}

Harl::~Harl() {}

void Harl::complain(std::string level) {
    std::string levels[] = {
        "DEBUG",
        "INFO",
        "WARNING",
        "ERROR"
    };
    FUN functions[] = {
        &Harl::debug,
        &Harl::info,
        &Harl::warning,
        &Harl::error,
    };
    for (size_t i = 0; i < (sizeof(levels) / sizeof(levels[0])); i++) 
        if (!levels[i].compare(level))
            (this->*(functions[i]))();
}
