# include "Zombie.hpp"

int main() {
    
    Zombie *zombie = newZombie("Erick");
    zombie->announce();
    randomChump("Jaquelina");

    delete zombie;
    return 0;
}