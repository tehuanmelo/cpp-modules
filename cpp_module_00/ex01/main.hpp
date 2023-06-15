/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-melo <tde-melo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 22:41:25 by tehuanmelo        #+#    #+#             */
/*   Updated: 2023/06/09 14:38:32 by tde-melo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
#define MAIN_H

#include <iostream>
#include <iomanip>

const std::string FNAME = "\x1b[32;3mFIRST NAME:\x1b[0m ";
const std::string LNAME = "\x1b[32;3mLAST NAME:\x1b[0m ";
const std::string NNAME = "\x1b[32;3mNICKNAME:\x1b[0m ";
const std::string PHONE = "\x1b[32;3mPHONE:(0123456789)\x1b[0m ";
const std::string SECRET = "\x1b[32;3mSECRET:\x1b[0m ";

void printHeader();
void printMenu();
std::string validateName(std::string input);
std::string validatePhone(std::string input);
std::string getUserString(std::string title);

#endif