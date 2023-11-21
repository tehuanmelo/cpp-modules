#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <map>
#include <cstdlib>

class Btc
{
private:
    std::map<std::string, double> dataBase;

public:
    Btc();
    ~Btc();
    Btc(Btc &copy);
    Btc &operator=(Btc &copy);

    void loadInput(std::string filePath);
    void setDataBase(std::string date, double value);
    void readDataBase(std::string filePath);
    void printDataBase();
};

void Btc::setDataBase(std::string date, double value)
{
    this->dataBase.insert(std::make_pair(date, value));
}

void Btc::readDataBase(std::string filePath)
{
    std::ifstream inputFile(filePath.c_str());
    if (!inputFile.is_open())
        std::cerr << "Couldn't open the database" << std::endl;
    std::string line;
    std::string date;
    double value;
    int firstLine = 0;
    while (getline(inputFile, line))
    {
        if (firstLine == 0) {
            firstLine = 1;
            continue;
        }
        size_t pos = line.find_first_of(',');
        if (pos == std::string::npos)
        {
            std::cerr << "Error: Invalid" << std::endl;
            continue;
        }
        std::string date = line.substr(0, pos);
        try
        {
            std::string cppString = line.substr(pos + 1);
            // const char *str = cppString.c_str();
            value = static_cast<double>(atof(cppString.c_str()));;
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
        }
        setDataBase(date, value);
    }
        inputFile.close();
}

void Btc::printDataBase()
{
    std::map<std::string, double>::iterator it;
    for (it = dataBase.begin(); it != dataBase.end(); ++it)
    {
        std::cout << "key: " << it->first << " value: " << it->second << std::endl;
    }
}

Btc::Btc(){
    this->readDataBase("data.csv");
    this->loadInput("input.txt");
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
    }
    return *this;
};

std::string trimString(const std::string& str) {
    size_t begin = str.find_first_not_of(" \t\n\r\f\v");
    size_t last = str.find_last_not_of(" \t\n\r\f\v");

    if (begin == std::string::npos)
        return "";  // Entire string is whitespace.

    if (last == std::string::npos)
        return str.substr(begin);  // No whitespaces at the end.

    return str.substr(begin, last - begin + 1);
}




bool isValidDate(const std::string& line) {
    if (line.length() != 10 && line[4] != '-' && line[7] != '-')
        return false;
    int read, year, month, day, maxDays;
    read = sscanf(line.c_str(), "%d-%d-%d", &year, &month, &day);
    if (read == 3) {
        if (month < 1 || month > 12)
            return false;
        switch (month)
        {
        case 2:
            maxDays = 28;
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
        return day >= 1 && day <= maxDays;
    }
    return false;
}

bool isValidValue(const std::string& value) {
    if (value.find_first_not_of("-0123456789.") != std::string::npos || value.find_first_of("0123456789") == std::string::npos)
        return false;
    size_t dotFirst = value.find_first_of(".");
    size_t dotLast = value.find_last_of(".");
    size_t dashFirst = value.find_first_of("-");
    size_t dashLast = value.find_last_of("-");
        if (dotFirst != dotLast || dotFirst == value.length() - 1 || dotFirst == 0 ||
            dashFirst != dashLast || dashFirst == value.length() - 1) {
            std::cerr << "Error: Bad Input => " << value << std::endl;
            return false;
            }
    int num = static_cast<double> (atof(value.c_str()));
    if (num < 1) {
        std::cerr << "Error: not a positive number" << std::endl;
        return false;
    } else if (num > 1000) {
        std::cerr << "Error: too large a number" << std::endl;
        return false;
    }
    return true;
    
}

bool validateLineInput(std::string line) {
    size_t barFirst = line.find_first_of("|");
    size_t barLast = line.find_last_of("|");
    if (line.find_first_not_of(" 0123456789-|.") != std::string::npos && barFirst != barLast && barFirst != std::string::npos) {
        std::cerr << "Error: Bad Input => " << line << std::endl;
        return false;
    }
    std::string date = trimString(line.substr(0, barFirst));
    std::string value = trimString(line.substr(barFirst + 1));
    return isValidDate(date) && isValidValue(value);
}

void Btc::loadInput(std::string filePath) {
   std::ifstream inputFile(filePath.c_str());
   if (!inputFile.is_open())
        std::cerr << "Couldn't open the input file" << std::endl;
    std::string line;
    // std::string date;
    bool atFirstLine = true;
    // double value;
    while (getline(inputFile, line)) {
        if (atFirstLine) {
            atFirstLine = false;
            continue;
        }
       if (!validateLineInput(line)) {
            continue;
       }
       std::cout << line << std::endl;
    }
    
}

int main(int ac, char **av)
{
    (void)ac;
    (void)av;
    Btc bit;

}
