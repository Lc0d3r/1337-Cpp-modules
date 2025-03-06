#include "FragTrap.hpp"

FragTrap::FragTrap() {
    std::cout << "FragTrap Default Constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap &copy)
{
    std::cout << "FragTrap Copy constructor called for " << this->name << std::endl ;
    *this = copy;
}

FragTrap& FragTrap::operator=(const FragTrap &src)
{
    std::cout << "FragTrap assignment operator called for " << this->name << std::endl ;
    this->name = src.name;
    this->attack_damage = src.attack_damage;
    this->hit_points = src.hit_points;
    this->energy_points = src.energy_points;
    return *this;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
    hit_points = 100;
    energy_points = 100;
    attack_damage = 30;
    std::cout << "FragTrap constructor executing." << std::endl;
}

FragTrap::~FragTrap(){
    std::cout << "FragTrap destructor executing." << std::endl;
}

void FragTrap::highFivesGuys(void) {
    std::cout << "High five! 🙌 Let’s celebrate this victory together!" << std::endl;
}