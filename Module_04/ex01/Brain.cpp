#include "Brain.hpp"

Brain::Brain() {
    std::cout << "Brain: Constructor called" << std::endl;
}

Brain::~Brain() {
    std::cout << "Brain: Destructor called" << std::endl;
}

Brain::Brain(const Brain& other) {
    *this = other;
}

Brain& Brain::operator=(const Brain& other) {
    for (int i = 0; i < 100; i++)
        this->ideas[i] = other.ideas[i];
    return *this;
}

std::string Brain::getIdea(int index) const {
    if (index < 0 || index >= 100) {
        std::cerr << "Error: Invalid Brain index: " << index << std::endl;
        return "";
    }
    return ideas[index];
}

void Brain::setIdea(int index, const std::string& idea) {
    if (index >= 0 && index < 100) {
        ideas[index] = idea;
    } else {
        std::cerr << "Error: Invalid Brain index: " << index << std::endl;
    }
}