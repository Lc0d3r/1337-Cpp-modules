#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"

class HumanB {
    public :
        std::string name;
        Weapon* weapon;
        void attack( void );
        void setWeapon( Weapon &weapon );
    HumanB(std::string name);
    ~HumanB();
};

#endif