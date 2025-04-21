#include "Dog.hpp"

Dog::Dog() {
    std::cout << "Dog: Default constructor called" << std::endl;
    brain = new Brain();
    type = "Dog";
}

Dog::Dog(const Dog& other) {
    type = other.type;
    brain = new Brain();
    *brain = *other.brain;
    // std::cout << "Dog: Copy constructor called" << std::endl;
}

Dog::~Dog() {
    std::cout << "Dog: Destructor called" << std::endl;
    delete brain;
};

Dog& Dog::operator=(const Dog& other) {
    this->type = other.type;
    *brain = *other.brain;
    return *this;
}

void Dog::makeSound() const {
    std::cout << "Woof!" << std::endl;
}

Brain* Dog::getBrain() const
{
    return this->brain;
}