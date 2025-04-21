#include "WrongCat.hpp"

WrongCat::WrongCat() {
    type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat& other) {
    *this = other;
}

WrongCat::~WrongCat() {};

WrongCat& WrongCat::operator=(const WrongCat& other) {
    this->type = other.type;
    return *this;
}