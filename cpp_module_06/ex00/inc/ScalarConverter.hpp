/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-melo <tde-melo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 17:34:11 by tehuanmelo        #+#    #+#             */
/*   Updated: 2023/10/13 20:44:04 by tde-melo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <limits>
#include <cstdlib>
#include <float.h>

struct Convert {
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
    ~ScalarConverter();
   
public:

    static void converter(std::string input);

    class InvalidInputException : public std::exception {
        const char *what() const throw();
    };
};

void checkPseudoLiterals(std::string input);
void isValidInput(std::string input);
void printOutput(Convert& numbers);
void printDouble(Convert& numbers);
void printFloat(Convert& numbers);
void printInt(Convert& numbers);
void printChar(Convert& numbers);
void convertAll(Convert& Convert, std::string input);
void convertChar(Convert& Convert, std::string input);

#endif