#include "BitcoinExchange.hpp"

int main(int argc, char** argv) {

    
    if (argc != 2) {
        std::cerr << "Program without param" << std::endl;
        return (1);
    }
    
    BitcoinExchange exchange(argv[1]);
    try {
        exchange.readDatabaseFromCSV();
        exchange.readInputFile();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
        return (1);
    }
    

    return (0);
}