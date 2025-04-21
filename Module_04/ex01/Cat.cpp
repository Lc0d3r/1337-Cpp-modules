#include "Cat.hpp"

Cat::Cat() {
    std::cout << "Cat: Default constructor called" << std::endl;
    brain = new Brain();
    type = "Cat";
}

Cat::Cat(const Cat& other) {
    type = other.type;
    brain = new Brain();
    *brain = *other.brain;
    // std::cout << "Cat: Copy constructor called" << std::endl;
}

Cat::~Cat() {
    std::cout << "Cat: Destructor called" << std::endl;
    delete brain;
};

Cat& Cat::operator=(const Cat& other) {
    this->type = other.type;
    *brain = *other.brain;
    return *this;
}

void Cat::makeSound() const {
    std::cout << "Meow." << std::endl;
}

Brain* Cat::getBrain() const
{
    return this->brain;
}