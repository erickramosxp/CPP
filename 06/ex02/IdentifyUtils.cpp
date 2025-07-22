#include "IdentifyUtils.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>


Base *generate() {

    int randomChoice;
    static bool initialized = false;

    if (!initialized) {
        srand(time(NULL));
        initialized = true;
    }

    randomChoice = rand() % 3;

    if (randomChoice == 0) {
        return new A();
    } else if (randomChoice == 1) {
        return new B();
    } else {
        return new C();
    }
};

void identify(Base* p) {

    if (p == NULL) {
        std::cout << "Object is not valid" << std::endl;
        return ;
    }

    if (dynamic_cast<A*>(p)) {
        std::cout << "This object is type A" << std::endl;
        return ;
    } else if (dynamic_cast<B*>(p)) {
        std::cout << "This object is type B" << std::endl;
        return ;
    } else if (dynamic_cast<C*>(p)) {
        std::cout << "This object is type C" << std::endl;
        return ;
    } else {
        std::cout << "This isn't one of these objects: A, B, C" << std::endl;
    }
};

void identify(Base& p) {

    try {
        dynamic_cast<A&>(p);
        std::cout << "This object is type A" << std::endl;
    } catch (...){
        try {
            dynamic_cast<B&>(p);
            std::cout << "This object is type B" << std::endl;
        } catch (...){
            try {
                dynamic_cast<C&>(p);
                std::cout << "This object is type C" << std::endl;
            } catch (...){
                std::cout << "This isn't one of these objects: A, B, C" << std::endl;
            }
        }
    }
};