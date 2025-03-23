# include "Zombie.hpp"

int main() {
    Zombie *zombie = new Zombie("Erick");
    zombie->announce();
    std::cout << "Hello, World!" << std::endl;
    zombie->randomChump("Jaquelina");

    delete zombie;
    return 0;
}