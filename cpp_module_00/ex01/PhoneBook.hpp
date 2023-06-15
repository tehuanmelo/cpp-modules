/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-melo <tde-melo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 01:08:36 by tehuanmelo        #+#    #+#             */
/*   Updated: 2023/06/09 14:32:55 by tde-melo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include "Contact.hpp"
#include "main.hpp"

class PhoneBook {
    private:
        int count;
        static const int size = 8;
        Contact array[size];

    public:
        PhoneBook();
        void addContact(Contact contact, int oldestIndex);
        void searchContact();
        int getOdelstIndex();
};

#endif
