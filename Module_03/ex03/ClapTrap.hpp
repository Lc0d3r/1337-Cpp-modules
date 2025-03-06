#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
    protected:
        std::string name;
        int hit_points;
        int energy_points;
        int attack_damage;
    public:
        // default constructor
        ClapTrap();
        // par constructor
        ClapTrap(std::string name);
        // copy Constructor
        ClapTrap(const ClapTrap &copy);
        // Assignment Operator
		ClapTrap &operator=(const ClapTrap &src);
        // destructor
        ~ClapTrap();
        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
};

#endif