#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap {
    private:
        std::string name;
    public :
        // default constructor
        DiamondTrap();
        // par constructor
        DiamondTrap(std::string name);
        // copy Constructor
        DiamondTrap(const DiamondTrap& copy);
        // Assignment Operator
        DiamondTrap &operator=(const DiamondTrap &src);
        // destructor
        ~DiamondTrap();

        // attak
        void attack(const std::string& target);
};

#endif