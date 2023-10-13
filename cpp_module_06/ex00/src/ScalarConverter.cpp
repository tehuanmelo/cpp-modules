/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tehuanmelo <tehuanmelo@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 17:36:51 by tehuanmelo        #+#    #+#             */
/*   Updated: 2023/10/12 13:43:54 by tehuanmelo       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ScalarConverter.hpp"

// #### PRIVATE MEMBERS ####

// constructors

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& copy) {
    (void)copy;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& copy) {
    (void)copy;
    return *this;
}

// ----------------------------------------------------------------------------

// #### PUBLIC MEMBERS ####

ScalarConverter::~ScalarConverter() {}

const char* ScalarConverter::InvalidInputException::what() const throw() {
    return "Invalid Input";
}

void ScalarConverter::converter(std::string input) {
    
    Convert numbers;
    
    try
    {
        if (input == "+inf" || input == "-inf" || input == "+inff" || 
        input == "-inff" || input == "nan" || input == "nanf") {
            checkPseudoLiterals(input);
            return;
        }
        
        isValidInput(input);
        
        if (input.length() == 1 && input.find_first_of("0123456789") == std::string::npos) {
            convertChar(numbers, input);
        } else if (input.find_first_not_of("+-0123456789.f") == std::string::npos) {
            convertAll(numbers, input);
        }
        else if (input.length() == 1 && std::isprint(input[0])) {
            convertChar(numbers, input);
        } else {
            throw ScalarConverter::InvalidInputException();
        }
        
        printOutput(numbers);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

// ----------------------------------------------------------------------------

void convertChar(Convert& numbers, std::string input) {
    numbers._char = static_cast<unsigned char>(input[0]);
    numbers._int = static_cast<int>(input[0]);
    numbers._double = static_cast<double>(input[0]);
    numbers._float = static_cast<float>(input[0]);
}

void convertAll(Convert& numbers, std::string input) {
    numbers._double = static_cast<double>(atof(input.c_str()));
    numbers._int = static_cast<int>(numbers._double);
    numbers._char = static_cast<unsigned char>(numbers._double);
    numbers._float = static_cast<float>(numbers._double);
}

void printChar(Convert& numbers) {
    if ((numbers._int >= 0 && numbers._int <= 127) && std::isprint(numbers._int))
        std::cout << "char: '" << numbers._char << "'" << std::endl;
    else   
        std::cout << "char: " << "non displayable" << std::endl;
}

void printInt(Convert& numbers) {
    if (numbers._double >= std::numeric_limits<int>::min() && 
    numbers._double <= std::numeric_limits<int>::max()) {
        std::cout << "int: " << numbers._int << std::endl;
    }
    else {
        std::cout << "int: " << "impossible" << std::endl;
    }
}

void printFloat(Convert& numbers) {
    if (numbers._double >= std::numeric_limits<float>::lowest() && 
    numbers._double <= std::numeric_limits<float>::max()) {
        std::cout << "float: " << numbers._double;
        if (numbers._double < 0 || (numbers._double - numbers._int) == 0)
            std::cout << ".0f" << std::endl;
        else    
            std::cout << "f" << std::endl;
    }
}

void printDouble(Convert& numbers) {
    std::cout << "double: " << numbers._double;
    if (numbers._double < 0 || (numbers._double - numbers._int) == 0)
        std::cout << ".0" << std::endl;
    else    
        std::cout << std::endl;
    
}

void printOutput(Convert& numbers) {
    printChar(numbers);
    printInt(numbers);
    printFloat(numbers);
    printDouble(numbers);
}

void isValidInput(std::string input) {
    if ((input.find_first_of(".") != input.find_last_of(".")) ||
    (input.find_first_of("f") != input.find_last_of("f")) || 
    (input.find_first_of("+-") != input.find_last_of("+-"))) 
        throw ScalarConverter::InvalidInputException();
}

void checkPseudoLiterals(std::string input) {
    if (input == "+inf" || input == "-inf") {
        std::cout 
        << "char: " << "impossible" << std::endl
        << "int: " << "impossible" << std::endl
        << "float: " << (input == "+inf" ? "+inff" : "-inff") << std::endl
        << "double: " << (input == "+inf" ? "+inf" : "-inf") << std::endl;  
    } else if (input == "+inff" || input == "-inff") {
        std::cout 
        << "char: " << "impossible" << std::endl
        << "int: " << "impossible" << std::endl
        << "float: " << (input == "+inff" ? "+inff" : "-inff") << std::endl
        << "double: " << (input == "+inff" ? "+inf" : "-inf") << std::endl;
    } else if (input == "nan" || input == "nanf") {
        std::cout 
        << "char: " << "impossible" << std::endl
        << "int: " << "impossible" << std::endl
        << "float: " << "nanf" << std::endl
        << "double: " << "nan" << std::endl;
    } 
}