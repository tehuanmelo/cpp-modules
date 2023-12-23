/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tehuanmelo <tehuanmelo@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 14:09:18 by tehuanmelo        #+#    #+#             */
/*   Updated: 2023/12/23 19:31:50 by tehuanmelo       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/BitcoinExchange.hpp"

Btc::Btc()
{
    this->readDataBase("data.csv");
};

Btc::~Btc(){};

Btc::Btc(Btc &copy)
{
    *this = copy;
};

Btc &Btc::operator=(Btc &copy)
{
    if (this != &copy)
    {
        this->dataBase.clear();
        std::map<std::string, double>::const_iterator it = copy.dataBase.begin();
        for (; it != copy.dataBase.end(); ++it)
            this->dataBase[it->first] = it->second;
    }
    return *this;
};

void Btc::setDataBase(std::string date, double value)
{
    this->dataBase.insert(std::make_pair(date, value));
}

void Btc::readDataBase(std::string filePath)
{
    std::ifstream inputFile(filePath.c_str());
    if (!inputFile.is_open())
        std::cerr << "Error: Couldn't open the database" << RESET << std::endl;
    std::string line;
    std::string date;
    double value;
    int firstLine = 0;
    while (getline(inputFile, line))
    {
        if (firstLine == 0)
        {
            firstLine = 1;
            continue;
        }
        size_t firstComma = line.find_first_of(',');
        size_t lastComma = line.find_first_of(',');
        if (firstComma == std::string::npos || firstComma != lastComma || line.find_first_not_of("0123456789-,. ") != std::string::npos)
        {
            std::cerr << "Error: Invalid data input => " << line << std::endl;
            continue;
        }
        std::string date = trimString(line.substr(0, firstComma));
        try
        {
            std::string cppValue = trimString(line.substr(firstComma + 1));
            value = static_cast<double>(atof(cppValue.c_str()));
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
        }
        setDataBase(date, value);
    }
    inputFile.close();
}

void Btc::loadInput(std::string filePath)
{
    std::ifstream inputFile(filePath.c_str());
    if (!inputFile.is_open())
        std::cerr << "Error: Couldn't open the input file" << std::endl;
    std::string line;
    bool atFirstLine = true;
    BtcData btcRate;
    while (getline(inputFile, line))
    {
        if (atFirstLine)
        {
            atFirstLine = false;
            continue;
        }
        if (line.empty() || !validateLineInput(line, btcRate))
            continue;
        std::map<std::string, double>::const_iterator it = findMatch(this->dataBase, btcRate.date);
        std::cout << it->first << " => " << btcRate.value << " = " << it->second * btcRate.value << std::endl;
    }
}

void Btc::printDataBase()
{
    std::map<std::string, double>::iterator it;
    for (it = dataBase.begin(); it != dataBase.end(); ++it)
    {
        std::cout << "key: " << it->first << " value: " << it->second << std::endl;
    }
}

std::string trimString(const std::string &str)
{
    size_t begin = str.find_first_not_of(" \t\n\r\f\v");
    size_t last = str.find_last_not_of(" \t\n\r\f\v");

    if (begin == std::string::npos)
        return ""; // Entire string is whitespace.

    if (last == std::string::npos)
        return str.substr(begin); // No whitespaces at the end.

    return str.substr(begin, last - begin + 1);
}

bool isValidDate(const std::string &date)
{
    if (date.length() != 10 || date[4] != '-' || date[7] != '-')
    {
        std::cerr << ERROR_MESSAGE << date << std::endl;
        return false;
    }
    int read, year, month, day, maxDays;
    read = sscanf(date.c_str(), "%d-%d-%d", &year, &month, &day);
    if (read == 3)
    {
        if (month < 1 || month > 12)
        {
            std::cerr << ERROR_MESSAGE << date << std::endl;
            return false;
        }
        switch (month)
        {
        case 2:
            maxDays = ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) ? 29 : 28;
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            maxDays = 30;
            break;
        default:
            maxDays = 31;
            break;
        }
    }
    if (day >= 1 && day <= maxDays)
        return true;
    std::cerr << ERROR_MESSAGE << date << std::endl;
    return false;
}

bool isValidValue(const std::string &value, double &btcValue)
{
    if (value.find_first_not_of("-0123456789.") != std::string::npos || value.find_first_of("0123456789") == std::string::npos)
    {
        std::cerr << ERROR_MESSAGE << value << std::endl;
        return false;
    }
    size_t dotFirst = value.find_first_of(".");
    size_t dotLast = value.find_last_of(".");
    size_t dashFirst = value.find_first_of("-");
    size_t dashLast = value.find_last_of("-");
    if (dotFirst != dotLast || dotFirst == value.length() - 1 || dotFirst == 0 || dashFirst != dashLast || dashFirst == value.length() - 1)
    {
        std::cerr << ERROR_MESSAGE << value << std::endl;
        return false;
    }
    int num;
    try
    {
        num = static_cast<double>(atof(value.c_str()));
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    if (num == 0)
    {
        std::cerr << ERROR_MESSAGE << num << std::endl;
        return false;
    }
    else if (num < 0)
    {
        std::cerr << RED << "Error: not a positive number" << RESET << std::endl;
        return false;
    }
    else if (num > 999)
    {
        std::cerr << RED << "Error: too large a number" << RESET << std::endl;
        return false;
    }
    btcValue = num;
    return true;
}

bool validateLineInput(std::string line, BtcData &btcRate)
{
    size_t barFirst = line.find_first_of("|");
    size_t barLast = line.find_last_of("|");
    if (line.find_first_not_of(" 0123456789-|.") != std::string::npos || barFirst == std::string::npos || barFirst != barLast)
    {
        std::cerr << ERROR_MESSAGE << line << std::endl;
        return false;
    }
    std::string date = trimString(line.substr(0, barFirst));
    std::string value = trimString(line.substr(barFirst + 1));
    if (date.empty() || value.empty())
    {
        std::cerr << ERROR_MESSAGE << value << std::endl;
        return false;
    }
    btcRate.date = date;
    return isValidDate(date) && isValidValue(value, btcRate.value);
}
