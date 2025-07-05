#include "Serializer.hpp"

Serializer::Serializer() {

};

uintptr_t Serializer::serialize(Data* ptr) {

    uintptr_t address;

    ptr->cookie = 0xFACEFEED;
    address = reinterpret_cast<uintptr_t>(ptr);

    return (address);
};

Data* Serializer::deserialize(uintptr_t raw) {

    Data *restore;

    restore = reinterpret_cast<Data*>(raw);

    if (!restore || restore->cookie != 0xFACEFEED) {
        std::cout << "Invalid data raw!" << std::endl;
        return (NULL);
    }

    std::cout << "Passei" << std::endl;
    return (restore);
};