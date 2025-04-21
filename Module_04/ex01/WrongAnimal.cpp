#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(): type("WrongAnimal") {
    std::cout << "WrongAnimal: Default constructor called" << std::endl;
};

WrongAnimal::WrongAnimal(const WrongAnimal& other) {
    *this = other;
}

WrongAnimal::~WrongAnimal() {
    std::cout << "WrongAnimal: Destructor called" << std::endl;
};

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other) {
    this->type = other.type;
    return *this;
}

std::string WrongAnimal::getType() const {
    return type;
}

void WrongAnimal::setType(std::string _type) {
    type = _type;
}

void WrongAnimal::makeSound() const {
    std::cout << "An WrongAnimale sound" << std::endl ;
}