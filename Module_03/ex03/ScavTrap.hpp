#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap {
public :
    // default constructor
    ScavTrap();
    // par constructor
    ScavTrap(std::string name);
    // copy Constructor
    ScavTrap(const ScavTrap& copy);
    // Assignment Operator
    ScavTrap &operator=(const ScavTrap &src);
    // destructor
    ~ScavTrap();
    void guardGate();
};

#endif