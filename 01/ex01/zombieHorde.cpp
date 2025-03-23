# include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name) {
    
    Zombie* zombies = new Zombie[N];
    int i = 0;

    while (i < N)
    {
        zombies[i].setName(name + " " + std::to_string(i));
        i++;
    }
    return zombies;
}