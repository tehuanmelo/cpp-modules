/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tehuanmelo <tehuanmelo@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 14:09:27 by tehuanmelo        #+#    #+#             */
/*   Updated: 2023/11/23 15:07:44 by tehuanmelo       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <map>
#include <cstdlib>
#include <algorithm>

#define RED "\x1b[31m"
#define RESET "\x1b[0m"
#define ERROR_MESSAGE "\x1b[31mError: Bad input => \x1b[0m"

struct BtcData
{
    std::string date;
    double value;
};

class Btc
{
private:
    std::map<std::string, double> dataBase;

public:
    Btc();
    ~Btc();
    Btc(Btc &copy);
    Btc &operator=(Btc &copy);

    void readDataBase(std::string filePath);
    void setDataBase(std::string date, double value);
    void loadInput(std::string filePath);
    void printDataBase();
};

std::string trimString(const std::string &str);
bool isValidDate(const std::string &date);
bool isValidValue(const std::string &value, double &btcValue);
bool validateLineInput(std::string line, BtcData &btcRate);

template <typename T>
typename T::const_iterator findMatch(const T &container, const std::string &date)
{
    typename T::const_iterator it = container.find(date);
    if (container.empty())
        return container.end();
    else if (it != container.end())
        return it;
    else
    {
        it = container.begin();
        while (it != container.end() && it->first < date)
            it++;
        return --it;
    }
    return container.end();
}

#endif