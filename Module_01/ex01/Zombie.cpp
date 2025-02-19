#include "Zombie.hpp"

void Zombie::announce ( void ) {
    std::cout << name << ": BraiiiiiiinnnzzzZ...\n";
}

Zombie::Zombie()
{};

void	Zombie::set_name(std::string name)  {
	this->name = name;
}

Zombie::~Zombie()
{
    std::cout << name << "\n";
}