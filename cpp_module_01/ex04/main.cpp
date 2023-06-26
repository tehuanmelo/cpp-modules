/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-melo <tde-melo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 09:33:25 by tehuanmelo        #+#    #+#             */
/*   Updated: 2023/06/26 14:55:32 by tde-melo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

int main(int ac, char **av)
{
    if (ac == 4) {
        std::string inFileName = av[1], s1 = av[2], s2 = av[3];
        std::ifstream inputfile(inFileName); //Open the infile
        if (s1.empty() || s2.empty()) {
            std::cout << "Invalid Input" << std::endl;
            return 1;
        }
        if (inputfile.is_open()) {
            std::string outFileName = inFileName + ".replace";
            std::ofstream outputfile(outFileName); // Creates and open the outFile
            if (outputfile.is_open()) { //check if the file is open
                copyFileContent(inputfile, outputfile, s1, s2);
                outputfile.close();
                inputfile.close();
            }
            else { //if inputfile was not open close the infile and exit
                inputfile.close();
                displayErrorFileExit();
            }
        }
        else 
            displayErrorFileExit();
    }
    else
        displayErrorArgs();
    return 0;
}