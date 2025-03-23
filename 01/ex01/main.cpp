#include "Zombie.hpp"

int main(void) {

    int n = 10;
    Zombie* horde = zombieHorde(n, "Lost zombie");

    for (int i = 0; i < n; i++) {
        horde[i].announce();
    }

    delete[] horde;
    return (0);
}