/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tehuanmelo <tehuanmelo@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 17:34:11 by tehuanmelo        #+#    #+#             */
/*   Updated: 2023/10/11 21:15:28 by tehuanmelo       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <limits>
#include <cstdlib>

struct convert {
    int _int;
    char _char;
    float _float;
    double _double;
};

class ScalarConverter
{
private:
    ScalarConverter();
    ScalarConverter(const ScalarConverter& copy);
    ScalarConverter& operator=(const ScalarConverter& copy);
   
public:
    ~ScalarConverter();

    static void converter(std::string input);

    class InvalidInputException : public std::exception {
        const char *what() const throw();
    };
};

#endif