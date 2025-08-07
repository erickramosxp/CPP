#include "BitcoinExchange.hpp"
#include <fstream>
#include <string>

BitcoinExchange::BitcoinExchange(std::string file) {
    this->fileComper = file;
};

BitcoinExchange::BitcoinExchange(const BitcoinExchange& exchange) {

    this->fileComper = exchange.fileComper;
};

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& exchange) {

    if (*this != &exchange) {

        this->fileComper = exchange.fileComper;
    }
    return *this;
};

BitcoinExchange::~BitcoinExchange() {

};

void BitcoinExchange::readDataFromCSV() {

    std::ifstream file("data.csv");

    if (!file.is_open()) {
        std::cout << "Error opening data file." << std::endl;
        return;
    }

    std::string line;
    while (std::getline(file, line)) {

        std::ostream os << line;
        std::string value;
        while (std::getline(os, value, ',')) {
            
        }
    }

    file.close();
};