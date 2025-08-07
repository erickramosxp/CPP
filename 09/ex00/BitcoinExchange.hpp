#pragma once

#include <iostream>

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
        void readDataFromCSV();
}