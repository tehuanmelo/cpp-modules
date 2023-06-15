/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tehuanmelo <tehuanmelo@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 09:33:25 by tehuanmelo        #+#    #+#             */
/*   Updated: 2023/06/10 14:12:59 by tehuanmelo       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
#define MAIN_H

#include <iostream>
#include <fstream>
#include <sstream>

void displayErrorArgs();
void displayErrorFileExit();
void clearFile(std::ifstream& file);
int getNumberOfLInes(std::ifstream& inputfile);
int getNbrOfWords(std::string line);
void copyFileContent(std::ifstream& inputfile, std::ofstream& outputfile, std::string s1, std::string s2);

#endif