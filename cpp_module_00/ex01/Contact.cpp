/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-melo <tde-melo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 01:08:43 by tehuanmelo        #+#    #+#             */
/*   Updated: 2023/06/15 15:21:11 by tde-melo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "main.hpp"

int Contact::nextId = 1;

void Contact::setContact(std::string fname, std::string lname, std::string number, std::string secret, std::string nickname) {
    FirstName = fname;
    LastName = lname;
    NickName = nickname;
    Number = number;
    Secret = secret;
    id = nextId++;
}

std::string getTruncatedString(std::string str) {
    std::string newStr;
    if (str.length() > 9)
        newStr = str.substr(0, 9) + '.';
    else
        newStr = str;
    return newStr;
}

void Contact::printList(int index) {
    std::cout << "\x1b[32m";
    std::cout << std::right << std::setw(10) << + index << "|"
        << std::right << std::setw(10) <<  getTruncatedString(FirstName) << "|"
        << std::right << std::setw(10) <<  getTruncatedString(LastName) << "|"
        << std::right << std::setw(10) <<  getTruncatedString(NickName) << "|" << std::endl;
    std::cout << "\x1b[0m";
}

void Contact::printContact() {
    std::cout << FNAME << FirstName << std::endl;
    std::cout << LNAME << LastName << std::endl;
    std::cout << NNAME << NickName << std::endl;
    std::cout << "\x1b[32;3mPHONE:\x1b[0m " << Number << std::endl;
    std::cout << SECRET << Secret << std::endl << std::endl;
}

std::string Contact::getName() {
    return FirstName;
}

int Contact::getId() {
    return id;
}

