#include "Animal.hpp"

Animal::Animal(): type("Animal") {
    std::cout << "Animal: Default constructor called" << std::endl;
};

Animal::Animal(const Animal& other) {
    *this = other;
}

Animal::~Animal() {
    std::cout << "Animal: Destructor called" << std::endl;
};

Animal& Animal::operator=(const Animal& other) {
    this->type = other.type;
    return *this;
}

std::string Animal::getType() const {
    return type;
}

void Animal::setType(std::string _type) {
    type = _type;
}

void Animal::makeSound() const {
    std::cout << "An animale sound" << std::endl ;
}