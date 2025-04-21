#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    std::cout << "=== Correct Polymorphism Test ===" << std::endl;
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    std::cout << "\nTypes:" << std::endl;
    std::cout << "j type: " << j->getType() << std::endl;
    std::cout << "i type: " << i->getType() << std::endl;

    std::cout << "\nSounds:" << std::endl;
    i->makeSound(); // Expected: Cat sound
    j->makeSound(); // Expected: Dog sound
    meta->makeSound(); // Expected: Animal sound

    delete meta;
    delete j;
    delete i;

    std::cout << "\n=== Wrong Polymorphism Test ===" << std::endl;
    const WrongAnimal* wrongMeta = new WrongAnimal();
    const WrongAnimal* wrongCat = new WrongCat();

    std::cout << "\nTypes:" << std::endl;
    std::cout << "wrongCat type: " << wrongCat->getType() << std::endl;

    std::cout << "\nSounds:" << std::endl;
    wrongMeta->makeSound();     // Expected: WrongAnimal sound
    wrongCat->makeSound();      // Expected: WrongAnimal sound, due to missing virtual function

    delete wrongMeta;
    delete wrongCat;

    return 0;
}
