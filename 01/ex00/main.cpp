# include "Zombie.hpp"

int main() {
    Zombie *zombie = new Zombie("Erick");
    zombie->announce();
    zombie->randomChump("Jaquelina");

    delete zombie;
    return 0;
}