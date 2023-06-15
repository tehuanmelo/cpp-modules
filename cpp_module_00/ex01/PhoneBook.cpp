/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-melo <tde-melo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 01:08:36 by tehuanmelo        #+#    #+#             */
/*   Updated: 2023/06/09 17:48:01 by tde-melo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"
#include "main.hpp"

PhoneBook::PhoneBook() {
    count = 0;
}

int PhoneBook::getOdelstIndex() {
    int min = array[0].getId();
    int index = 0;
    for (int i = 0; i < count; i++) {
        if (array[i].getId() < min)
            min = array[i].getId();
    }
    for (int i = 0; i < count; i++) {
        if (array[i].getId() == min)
            index = i;
    }
    return index;
}

void PhoneBook::addContact(Contact contact, int oldestIndex) {
    if (count < size) {
        array[count] = contact;
        count++;
    }
    else 
        array[oldestIndex] = contact;
}

void PhoneBook::searchContact() {
    std::string input;
    int index;
    do {
        printHeader();
        std::cout << "SEARCH MODE" << std::endl << std::endl;
        std::cout << std::right << std::setw(10) <<  "INDEX" << "|"
            << std::right << std::setw(10) <<  "F. NAME" << "|"
            << std::right << std::setw(10) <<  "L. NAME" << "|"
            << std::right << std::setw(10) <<  "NICKNAME" << "|" << std::endl;
        for (int i = 0; i < count; i++) 
            array[i].printList(i + 1);
        std::cout << std::endl << "Type index to display the contact or 0 to go back to main menu: ";
        std::cin >> input;
        if (input.empty())
            exit(0);
        if (input == "0") {
            printMenu();
            std::cin.ignore();
            return;
        }
        index = std::stoi(input);
    } while (index < 0 || index > count);
    
    printMenu();
    array[index - 1].printContact();
    std::cin.ignore();
}
