#pragma once

#include <iostream>
#include <map>

class BitcoinExchange {

    private:
    
        std::map<std::string, std::string> data;
        std::string fileComper;

        BitcoinExchange();
    public:

        BitcoinExchange(std::string file);
        BitcoinExchange(const BitcoinExchange& exchange);
        BitcoinExchange& operator=(const BitcoinExchange& exchange);
        ~BitcoinExchange();
        void readDatabaseFromCSV();
        void readInputFile();
        void getPreviousDateToConversion(const std::string& key, const std::string& value);
};