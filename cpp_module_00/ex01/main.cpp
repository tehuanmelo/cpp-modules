/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-melo <tde-melo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 01:08:36 by tehuanmelo        #+#    #+#             */
/*   Updated: 2023/06/15 16:36:00 by tde-melo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"
#include "main.hpp"

Contact addContact() {
    Contact contact;
    printHeader();
    std::cout << "ADD MODE" << std::endl << std::endl;
    std::cout << "Insert new contact:" << std::endl;
    std::string fname = getUserString(FNAME);
    std::string lname = getUserString(LNAME);
    std::string nickname = getUserString(NNAME);
    std::string number = getUserString(PHONE);
    std::string secret = getUserString(SECRET);
    contact.setContact(fname, lname, number, secret, nickname);
    return contact;
}

int main() {
    printMenu();
    std::string command;
    Contact contact;
    PhoneBook phone_book;
    do
    {
        
        if(!std::getline(std::cin, command))
            return 1;
        std::cout << command << std::endl;
        for (size_t i = 0; i < command.length(); i++)
            command[i] = char(std::tolower(command[i]));

        if (command == "add") {
            contact = addContact();
            phone_book.addContact(contact, phone_book.getOdelstIndex());
            printMenu();
            
        }
        else if (command == "search") {
            phone_book.searchContact();
        }
        else {
            printMenu();
            std::cout << "\x1b[31;3m**INVALID COMMAND**\x1b[0m" << std::endl;
        }
    } while (command != "exit");
}