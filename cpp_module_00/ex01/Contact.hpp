/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tehuanmelo <tehuanmelo@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 01:08:43 by tehuanmelo        #+#    #+#             */
/*   Updated: 2023/06/05 14:01:04 by tehuanmelo       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_H
#define CONTACT_H

#include "main.hpp"

class Contact {
    private:
        static int nextId;
        int id;
        std::string FirstName;
        std::string LastName;
        std::string NickName;
        std::string Number;
        std::string Secret;

    public:
        void setContact(std::string fname, std::string lname, std::string number, std::string secret, std::string nickname);
        void printList(int index);
        void printContact();
        std::string getName();
        int getId();
};

#endif