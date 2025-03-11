#include "ClapTrap.hpp"

int main() {
    ClapTrap clap1("Clappy");
    ClapTrap clap2("Trappy");

    clap1.attack("Trappy");
    clap2.takeDamage(0);

    clap2.attack("Clappy");
    clap1.takeDamage(0);

    clap1.beRepaired(5);
    clap2.beRepaired(3);

    for (int i = 0; i < 10; i++) {
        clap1.attack("Trappy");
    }

    clap1.attack("Trappy");  // Should fail due to no energy left
    clap1.beRepaired(5);     // Should fail due to no energy left

    return 0;
}
