# include "Zombie.hpp"

Zombie::Zombie(std::string name) {
    this->name = name;
}

void Zombie::announce(void) {
    std::cout << "<" << this->name << "> BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie* Zombie::newZombie(std::string name) {
    return new Zombie(name);
}

void Zombie::randomChump(std::string name) {
    Zombie(name).announce();
}