/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-melo <tde-melo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 17:36:51 by tehuanmelo        #+#    #+#             */
/*   Updated: 2023/10/13 21:43:03 by tde-melo         ###   ########.fr       */
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
    if ((numbers._int >= 0 && numbers._int <= 127) && std::isprint(numbers._int) && (numbers._double - numbers._int) == 0)
        std::cout << "char: '" << numbers._char << "'" << std::endl;
    else if ((numbers._int >= 0 && numbers._int <= 127) && !std::isprint(numbers._int) && (numbers._double - numbers._int) == 0)
        std::cout << "char: " << "non displayable" << std::endl;
    else 
        std::cout << "char: " << "impossible" << std::endl;
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
    if (numbers._double >= (-FLT_MAX - 1) && 
    numbers._double <= FLT_MAX) {
        std::cout << "float: " << numbers._double;
        if ((numbers._double - numbers._int) == 0)
            std::cout << ".0f" << std::endl;
        else    
            std::cout << "f" << std::endl;
    }
    else    
        std::cout << "float: " << "impossible" << std::endl;
        
}

void printDouble(Convert& numbers) {
    std::cout << "double: " << numbers._double;
    if ((numbers._double - numbers._int) == 0){
        std::cout << ".0" << std::endl;
    }
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
    size_t dotFirst = input.find_first_of(".");
    size_t dotLast = input.find_first_of(".");
    size_t fFirst = input.find_first_of("f");
    size_t fLast = input.find_first_of("f");
    
    if (dotFirst != dotLast || fFirst != fLast || 
    (fFirst != std::string::npos && fFirst != (input.length() - 1)) || 
    (dotFirst == std::string::npos && fFirst != std::string::npos) || 
    (input.find_first_of("+-") != input.find_last_of("+-"))) 
        throw ScalarConverter::InvalidInputException();
}

void checkPseudoLiterals(std::string input) {

    if (input == "+inf" || input == "-inf") {
        std::cout 
        << "char: " << "impossible" << std::endl
        << "int: " << "impossible" << std::endl
        << "float: " << (input == "+inf" ? std::numeric_limits<float>::infinity() : -std::numeric_limits<float>::infinity()) << "f" << std::endl
        << "double: " << (input == "+inf" ? std::numeric_limits<double>::infinity() : -std::numeric_limits<double>::infinity()) << std::endl;
    } else if (input == "+inff" || input == "-inff") {
        std::cout 
        << "char: " << "impossible" << std::endl
        << "int: " << "impossible" << std::endl
        << "float: " << (input == "+inff" ? std::numeric_limits<float>::infinity() : -std::numeric_limits<float>::infinity()) << "f" << std::endl
        << "double: " << (input == "+inff" ? std::numeric_limits<double>::infinity() : -std::numeric_limits<double>::infinity()) << std::endl;
    } else if (input == "nan" || input == "nanf") {
        std::cout 
        << "char: " << "impossible" << std::endl
        << "int: " << "impossible" << std::endl
        << "float: " << std::numeric_limits<float>::quiet_NaN() << "f" << std::endl
        << "double: " << std::numeric_limits<double>::quiet_NaN() << std::endl;
    } 
}