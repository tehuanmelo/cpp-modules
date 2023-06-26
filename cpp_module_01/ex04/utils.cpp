/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-melo <tde-melo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 09:33:25 by tehuanmelo        #+#    #+#             */
/*   Updated: 2023/06/26 14:46:07 by tde-melo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

void displayErrorArgs() {
        std::cout << "invalid input" << std::endl;
}

void displayErrorFileExit() {
        std::cout << "Error couldn't open the file" << std::endl;
        exit(0);
}

void clearFile(std::ifstream& file) {
    file.clear(); //clear any error flag
    file.seekg(0, std::ios::beg); //reset the pointer to the beginning of the file
}

int getNumberOfLInes(std::ifstream& inputfile) {
    int nbrOfLines = 0;
    std::string line;
    while (std::getline(inputfile, line)) 
        nbrOfLines++;
    clearFile(inputfile);
    return nbrOfLines;
}

int getNbrOfWords(std::string line) {
    std::stringstream ss(line);
    std::string word;
    int wordCount = 0;
    while (ss >> word)
        wordCount++;
    return wordCount;
}

void copyFileContent(std::ifstream& inputfile, std::ofstream& outputfile, std::string s1, std::string s2) {
    std::string line;
    int nbrOfLines = getNumberOfLInes(inputfile);
    while (std::getline(inputfile, line)) { //get each line of the file
        std::size_t position = line.find(s1);
        if (position != std::string::npos) {
            line.erase(position, s1.length());
            line.insert(position, s2);
        }
        outputfile << line;
        if (nbrOfLines > 1) {
            outputfile << std::endl;
            nbrOfLines--;
        }
    }
}
