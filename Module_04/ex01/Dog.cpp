#include "Dog.hpp"

Dog::Dog() {
    std::cout << "Dog: Default constructor called" << std::endl;
    type = "Dog";
}

Dog::Dog(const Dog& other) {
    *this = other;
}

Dog::~Dog() {
    std::cout << "Dog: Destructor called" << std::endl;
};

Dog& Dog::operator=(const Dog& other) {
    this->type = other.type;
    return *this;
}

void Dog::makeSound() const {
    std::cout << "Woof!" << std::endl;
}