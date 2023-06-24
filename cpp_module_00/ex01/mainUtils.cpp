/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainUtils.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tehuanmelo <tehuanmelo@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 01:08:36 by tehuanmelo        #+#    #+#             */
/*   Updated: 2023/06/24 15:01:06 by tehuanmelo       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"
#include "main.hpp"


void printHeader() {
    std::system("clear");
    std::cout << "\x1b[34;47;1m ************************************ " << std::endl;
    std::cout << " **                                ** " << std::endl;
    std::cout << " **  WELCOME TO THE PHONEBOOK APP  ** " << std::endl;
    std::cout << " **                                ** " << std::endl;
    std::cout << " ************************************ \x1b[0m" << std::endl;
    std::cout << std::endl;
}

void printMenu() {
    std::system("clear");
    printHeader();
    std::cout << "type ADD to insert a new contact: " << std::endl;
    std::cout << "type SEARCH to search for a contact: " << std::endl;
    std::cout << "type EXIT to exit the app: " << std::endl;
    std::cout << std::endl;
}

std::string validateName(std::string input) {
    for (size_t i = 0; i < input.length(); i++) {
        if (!std::isalpha(input[i]) && input[i] != ' ') {
            input = "";
            break;
        }
    }
    return input;
}

std::string validateNickName(std::string input) {
    for (size_t i = 0; i < input.length(); i++) {
        if (!std::isalpha(input[i]) && !std::isdigit(input[i]) && input[i] != ' ') {
            input = "";
            break;
        }
    }
    return input;
}

std::string validatePhone(std::string input) {
    if (input.length() != 10)
        input = "";
    else {
        for (size_t i = 0; i < input.length(); i++) {
            if (!std::isdigit(input[i])) {
                input = "";
                break;
            }
        }
    }
    return input;
}

std::string getUserString(std::string title) {
    std::string input;
    do {
        std::cout << title;
        if (!std::getline(std::cin, input))
            exit(0);
        if (title == FNAME || title == LNAME)
            input = validateName(input);
        else if (title == NNAME)
            input = validateNickName(input);
        else if (title == PHONE)
            input = validatePhone(input);
        if (input.empty())
            std::cout << "\x1b[31;3m**INVALID INPUT**\x1b[0m" << std::endl;
    } while (input.empty());
    
    return input;
}

