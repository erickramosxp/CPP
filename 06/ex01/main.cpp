
#include "Serializer.hpp"

int main() {

    uintptr_t raw;

    Data sData;

    sData.name = "Teste";
    sData.x = 10;
    sData.y = 30;

    std::cout << "Values of sData before serialize" << std::endl;
    std::cout << "Data->name: " << sData.name << std::endl;
    std::cout << "Data->x: " << sData.x << std::endl;
    std::cout << "Data->y: " << sData.y << std::endl;

    raw = Serializer::serialize(&sData);

    std::cout << "\nValue of uintptr_t after serialize: " << raw << std::endl;

    Data *tData = NULL;
    
    tData = Serializer::deserialize(raw);

    if (tData) {
        std::cout << "\nValues of tData after deserialize" << std::endl;
        std::cout << "Data->name: " << tData->name << std::endl;
        std::cout << "Data->x: " << tData->x << std::endl;
        std::cout << "Data->y: " << tData->y << std::endl;
    }


    std::cout << &sData << std::endl;
    std::cout << tData << std::endl;

    if (tData == &sData) {
        std::cout << "Success: deserialized pointer matches original!" << std::endl;
    } else {
        std::cout << "Failure: pointers differ!" << std::endl;
    }

    return (0);
}