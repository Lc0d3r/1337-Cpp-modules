#include "Span.hpp"

Span::Span(unsigned int n) {
    this->maxSize = n;
}

Span::Span(const Span &other) {
    *this = other;
}

Span &Span::operator=(const Span &other) {
    if (this != &other) {
        this->maxSize = other.maxSize;
        this->numbers.clear(); 
        std::vector<int>::const_iterator cito = other.numbers.begin();
        while (cito != other.numbers.end()) {
            this->numbers.push_back(*cito);
            cito++;
        }
    }
    return *this;
}

Span::~Span() {};

void Span::addNumber(int number) {
    if (this->numbers.size() < this->maxSize)
        this->numbers.push_back(number);
    else 
        throw ThereIsNoSpaceLeft();
}

const char *Span::ThereIsNoSpaceLeft::what() const throw() {
    return "There is no space left exception";
}

void Span::addNumbers(std::vector<int>::iterator first, std::vector<int>::iterator last) {
    if (std::distance(first,last) + this->numbers.size() < this->maxSize) 
        this->numbers.insert(this->numbers.end(), first, last);
    else 
        throw ThereIsNoSpaceLeft();
}

unsigned int Span::shortestSpan()  {
    std::sort(this->numbers.begin(), this->numbers.end());
    std::vector<int>::iterator it = this->numbers.begin();
    if (this->numbers.size() >= 2){
        int minSpan = *(it + 1) - *it;
        while (it != this->numbers.end() - 1) {
            if ((*(it + 1) - *it) < minSpan)
                minSpan = *(it + 1) - *it;
            it++;
        }
        return minSpan;
    }
    else
        throw NoSpanCanBeFound();
}

unsigned int Span::longestSpan()  {
    std::sort(this->numbers.begin(), this->numbers.end());
    if (this->numbers.size() >= 2)
        return (*(this->numbers.end()-1) - *(this->numbers.begin()));
    else
        throw NoSpanCanBeFound();
}

const char *Span::NoSpanCanBeFound::what() const throw() {
    return "No Span Can Be Found";
}

void Span::printNumbers()  {
    std::vector<int>::iterator it = this->numbers.begin();
    while (it != this->numbers.end()) {
        std::cout << "print => " <<*it << std::endl;
        it++;
    }
}