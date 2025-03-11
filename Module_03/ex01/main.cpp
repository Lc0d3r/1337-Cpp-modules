#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main() {
    // Testing ClapTrap
    ClapTrap clap("Clappy");
    clap.attack("Target A");
    clap.takeDamage(3);
    clap.beRepaired(5);
    
    // Testing ScavTrap
    ScavTrap scav("Scavvy");
    scav.attack("Target B");
    scav.takeDamage(30);
    scav.beRepaired(20);
    
    // Testing Gatekeeper mode
    scav.guardGate();
    
    // Depleting energy points
    for (int i = 0; i < 50; i++) {
        scav.attack("Target C");
    }
    
    scav.attack("Target C"); // Should fail due to no energy left

    return 0;
}
