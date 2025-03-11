#include "ClapTrap.hpp"

ClapTrap::ClapTrap(): name("default"), hit_points(10), energy_points(10), attack_damage(0) {
	std::cout << "ClapTrap Default Constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : name(name), hit_points(10), energy_points(10), attack_damage(0) {
    std::cout << "ClapTrap Constructor called for " << this->name << std::endl ;
};

ClapTrap::~ClapTrap(){
    std::cout << "ClapTrap Destructor called for " << this->name << std::endl ;
};

ClapTrap::ClapTrap(const ClapTrap &copy)
{
    std::cout << "ClapTrap Copy constructor called for " << this->name << std::endl ;
    *this = copy;
}

ClapTrap& ClapTrap::operator=(const ClapTrap &src)
{
    std::cout << "ClapTrap assignment operator called for " << this->name << std::endl ;
    this->name = src.name;
    this->attack_damage = src.attack_damage;
    this->hit_points = src.hit_points;
    this->energy_points = src.energy_points;
    return *this;
}

void ClapTrap::attack(const std::string& target) {
    if (this->hit_points >= 1 && this->energy_points >= 1)
    {
        std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing "<< this->attack_damage <<" points of damage!" << std::endl;
        this->energy_points--;
        return;
    }
    std::cout << "ClapTrap " << this->name << " tried to attack but there is no energy points or hit points available"<< std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
    std::cout << "ClapTrap " << this->name << " takes " << amount <<" points of damage!" << std::endl;
    this->hit_points -= amount;
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (this->energy_points >= 1)
    {
        std::cout << "ClapTrap " << this->name << " repaired "<< "with amount of "<< amount <<std::endl;
        this->hit_points += amount;
        this->energy_points--;
        return;
    }
    std::cout << "ClapTrap " << this->name << " tried to be repaired but there is not energy points available"<< std::endl;
}