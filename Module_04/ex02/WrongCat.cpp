#include "WrongCat.hpp"

WrongCat::WrongCat() {
    std::cout << "WrongCat: Default constructor called" << std::endl;
    type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat& other) {
    *this = other;
}

WrongCat::~WrongCat() {
    std::cout << "WrongCat: Destructor called" << std::endl;
};

WrongCat& WrongCat::operator=(const WrongCat& other) {
    this->type = other.type;
    return *this;
}