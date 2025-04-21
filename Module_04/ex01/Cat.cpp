#include "Cat.hpp"

Cat::Cat() {
    std::cout << "Cat: Default constructor called" << std::endl;
    type = "Cat";
}

Cat::Cat(const Cat& other) {
    *this = other;
}

Cat::~Cat() {
    std::cout << "Cat: Destructor called" << std::endl;
};

Cat& Cat::operator=(const Cat& other) {
    this->type = other.type;
    return *this;
}

void Cat::makeSound() const {
    std::cout << "Meow." << std::endl;
}