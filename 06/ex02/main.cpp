#include "IdentifyUtils.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

int main() {


    Base* random = generate();

    identify(random);

    Base* randomTwo = generate();

    Base &constRandom = *randomTwo;
    
    identify(constRandom);
    
    delete randomTwo;
    delete random;

    return (0);
}