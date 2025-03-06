#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap{
    public :
        // default constructor
        FragTrap();
        // par constructor
        FragTrap(std::string name);
        // copy Constructor
        FragTrap(const FragTrap& copy);
        // Assignment Operator
        FragTrap &operator=(const FragTrap& src);
        // destructor
        ~FragTrap();
        void highFivesGuys(void);
};

#endif