#include "BitcoinExchange.hpp"
#include <fstream>
#include <string>
#include <sstream>
#include <cstddef>
#include <cctype>
#include <cstdlib>
#include <iomanip>
#include <exception>
#include <cmath>

BitcoinExchange::BitcoinExchange(std::string file) {
    this->fileComper = file;
};

BitcoinExchange::BitcoinExchange(const BitcoinExchange& exchange) {

    *this = exchange;
};

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& exchange) {

    if (this != &exchange) {

        this->fileComper = exchange.fileComper;
        this->data = exchange.data;
    }
    return *this;
};

BitcoinExchange::~BitcoinExchange() {

};

bool isNum(std::string value) {

    for (size_t i = 0; i < value.size(); i++) {
        if (!std::isdigit(value.at(i))) {
            return false;
        }
    }
    return true;
}

bool validateValue(const std::string& value) {

    bool isDot = false;
    bool isNegative = false;

    size_t i = 0;
    if (value[0] == '-') {
        i++;
        isNegative = true;
    }
    for ( ;i < value.size(); i++) {

        if (!isDot && value.at(i) == '.') {
            isDot = true;
            continue;
        } else if ((isDot && value.at(i) == '.') || !std::isdigit(value.at(i))) {
            std::cout << "Value '" << value << "' is not valid." << std::endl;
            return false;
        }
    }

    if (isNegative) {
        std::cout << "Error: not a positive number." << std::endl;
        return false;
    }

    return true;
}

bool validateDate(const std::string& date) {

    size_t pos, prevPos;
    std::string year, month, day;
    
    pos = date.find('-');
    if (pos == std::string::npos) {
        std::cout << "Error: bad input => " << date << std::endl;
        return false;
    }
    year = date.substr(0, pos);
    prevPos = pos;
    pos = date.find('-', pos + 1);
    if (pos == std::string::npos) {
        std::cout << "Error: bad input => " << date << std::endl;
        return false;
    }
    month = date.substr(year.size() + 1, pos - prevPos - 1);
    day = date.substr(pos + 1, date.size() - pos);

    if (!isNum(year) || !isNum(month) || !isNum(day)) {
        std::cout << "Date not valid." << std::endl;
        return false;
    }

    if ((month.size() > 2 || std::atoi(month.c_str()) > 12) ||
     std::atoi(day.c_str()) > 31 || day.size() > 2 || year.size() > 4) {
        std::cout << "Error: bad input => " << date << std::endl;
        return false;
    }
    
    return true;
}

void BitcoinExchange::readDatabaseFromCSV() {

    std::ifstream file("data.csv");

    if (!file.is_open()) {
        throw std::runtime_error("Error opening database file.");
    }

    std::string line;
    while (std::getline(file, line)) {

        std::istringstream is(line);
        std::string key, value;

        if (std::getline(is, key, ',') && std::getline(is, value)) {
            if (key == "date")
                continue ;
            if (!validateDate(key) || !validateValue(value))
                throw std::runtime_error("Error in database format.");
            this->data[key] = value;
        }
    }

    file.close();
};

void removeSpace(std::string& str) {

    std::string::iterator itb = str.begin();

    while (itb != str.end())
    {
        if (std::isspace(*itb)) {
            itb = str.erase(itb);
        } else {
            itb++;
        }
    }

    std::string::iterator ite = str.end();
    while (ite != str.begin())
    {
        ite--;
        if (std::isspace(*ite)) {
            ite = str.erase(ite);
        }
    }    
}


void printConversion(const std::string& key, const std::string& value, const std::string& btc) {

    double totalValue = std::strtod(value.c_str(), NULL);
    double quantityBTC = std::strtod(btc.c_str(), NULL);

    if (quantityBTC > 1000) {
        std::cout << "Error: too large a number." << std::endl;
        return ;
    }

    double result = totalValue * quantityBTC;
    
    // Format with 2 decimal places but remove trailing zeros
    std::cout << key << " => " << btc << " = ";
    
    // Round to 2 decimal places
    result = std::floor(result * 100 + 0.5) / 100;
    
    // Print with up to 2 decimal places, but remove trailing zeros
    std::ostringstream oss;
    oss << std::fixed << std::setprecision(2) << result;
    std::string resultStr = oss.str();
    
    // Remove trailing zeros
    size_t dotPos = resultStr.find('.');
    if (dotPos != std::string::npos) {
        size_t lastNonZero = resultStr.find_last_not_of('0');
        if (lastNonZero != std::string::npos && lastNonZero >= dotPos) {
            if (lastNonZero == dotPos) {
                // All decimals are zero, keep one
                resultStr = resultStr.substr(0, dotPos + 2);
            } else {
                resultStr = resultStr.substr(0, lastNonZero + 1);
            }
        }
    }
    
    std::cout << resultStr << std::endl;
}

void BitcoinExchange::getPreviousDateToConversion(const std::string& key, const std::string& value) {

    this->data[key] = "0";
    
    std::map<std::string, std::string>::iterator it = this->data.find(key);

    if (it != data.begin()) {
        --it;
        printConversion(key, it->second, value);                        
    } else {
        std::cout << "Date " << key << " not founded in database" << std::endl;
    }
    this->data.erase(key);

}

void BitcoinExchange::readInputFile() {

    std::ifstream file(this->fileComper.c_str());

    if (!file.is_open()) {
        std::cerr << "Error: could not open file." << std::endl;
        return;
    }

    std::string line;
    while (std::getline(file, line)) {

        std::istringstream is(line);
        std::string key, value;

        if (std::getline(is, key, '|')) {
            
            removeSpace(key);
            if (key == "date")
                continue ;
            
            
            if (std::getline(is, value)) {
                removeSpace(value);
                if (!validateDate(key) || !validateValue(value))
                    continue ;
                if (!this->data[key].empty()) {
                    printConversion(key, this->data[key], value);                   
                } else {
                    getPreviousDateToConversion(key, value);
                }
            } else {
                std::cout << "Error: bad input => " << key << std::endl;
            }
        }
    }
}