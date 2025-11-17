#include "BitcoinExchange.hpp"

int main(int argc, char** argv) {

    
    if (argc != 2) {
        std::cerr << "Error: could not open file." << std::endl;
        return (1);
    }
    
    BitcoinExchange exchange(argv[1]);
    try {
        exchange.readDatabaseFromCSV();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
        return (1);
    }
    
    exchange.readInputFile();

    return (0);
}