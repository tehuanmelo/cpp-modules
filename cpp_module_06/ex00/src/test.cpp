/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tehuanmelo <tehuanmelo@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 18:02:52 by tehuanmelo        #+#    #+#             */
/*   Updated: 2023/10/10 20:34:15 by tehuanmelo       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

class ScalarConverter {
public:
    static void convert(const std::string& input);
};

void ScalarConverter::convert(const std::string& input) {
    // Check for special float and double cases
    if (input == "-inff" || input == "+inff" || input == "nanf") {
        // Handle float special cases
        std::cout 
        << "char: impossible\n" 
        << "int: impossible\n"
        << "float: " << input << "\n"
        << "double: " << (input == "nanf" ? "nan" : "inf") 
        << std::endl;
        return;
    } else if (input == "-inf" || input == "+inf" || input == "nan") {
        // Handle double special cases
        std::cout 
        << "char: impossible\n" 
        << "int: impossible\n"
        << "float: " << (input == "nan" ? "nanf" : "inff") << "\n"
        << "double: " << input 
        << std::endl;
        return;
    }

    // Check if it's a single character
    if (input.length() == 1) {
        char c = input[0];
        int i = static_cast<int>(c);
        float f = static_cast<float>(c);
        double d = static_cast<double>(c);
        
        std::cout << "char: '" << c << "'\nint: " << i << "\nfloat: " << f << "\ndouble: " << d << std::endl;
        return;
    }

    // Try converting to int
    try {
        int i = std::stoi(input);
        char c = static_cast<char>(i);
        float f = static_cast<float>(i);
        double d = static_cast<double>(i);

        std::cout << "char: '" << c << "'\nint: " << i << "\nfloat: " << f << "\ndouble: " << d << std::endl;
        return;
    } catch (const std::exception& e) {
        // Handle integer conversion error
    }

    // Try converting to float
    try {
        float f = std::stof(input);
        char c = static_cast<char>(f);
        int i = static_cast<int>(f);
        double d = static_cast<double>(f);

        std::cout << "char: '" << c << "'\nint: " << i << "\nfloat: " << f << "\ndouble: " << d << std::endl;
        return;
    } catch (const std::exception& e) {
        // Handle float conversion error
    }

    // Try converting to double
    try {
        double d = std::stod(input);
        char c = static_cast<char>(d);
        int i = static_cast<int>(d);
        float f = static_cast<float>(d);

        std::cout << "char: '" << c << "'\nint: " << i << "\nfloat: " << f << "\ndouble: " << d << std::endl;
        return;
    } catch (const std::exception& e) {
        // Handle double conversion error
    }

    // If no valid conversion was found, display an error message
    std::cout << "char: impossible\nint: impossible\nfloat: impossible\ndouble: impossible" << std::endl;
}

int main() {
    ScalarConverter::convert("99999999999999999999999");     // Test with an integer
    // ScalarConverter::convert("42.0f"); // Test with a float
    // ScalarConverter::convert("nanf");  // Test with a float special case
    // ScalarConverter::convert("x");     // Test with a single character
    // ScalarConverter::convert("abc");   // Test with invalid input

}
