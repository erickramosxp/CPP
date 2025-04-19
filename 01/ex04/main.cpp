
#include "ReadMyFile.hpp"

int main(int argc, char **argv)
{

    if (argc != 4) {
        std::cout << "The program needs three aguments <filename> <word in file> <new word>" << std::endl;
        return (1);
    }
    
    std::string oldStr = argv[2];
    std::string newStr = argv[3];
    ReadMyFile file(argv[1]);

    if (!file.open()) {
        std::cout << "Fail in open the file" << std::endl;
        return (1);
    }
    file.replaceAll(oldStr,newStr);
    return (0);
}