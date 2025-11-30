#include <iostream>
#include <vector>
#include <list>
#include <cstdlib>
#include <ctime>
#include "Span.hpp"

int main() {
    std::cout << "=== Test 1: Basic functionality from subject ===" << std::endl;
    try {
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        
        sp.printNumbers();
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 2: Adding too many numbers ===" << std::endl;
    try {
        Span sp = Span(3);
        sp.addNumber(1);
        sp.addNumber(2);
        sp.addNumber(3);
        sp.addNumber(4); // This should throw ThereIsNoSpaceLeft
    } catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 3: Not enough numbers for span ===" << std::endl;
    try {
        Span sp = Span(5);
        sp.addNumber(1);
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl; // Should throw NoSpanCanBeFound
    } catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 4: Single number ===" << std::endl;
    try {
        Span sp = Span(5);
        sp.addNumber(42);
        std::cout << "Longest span: " << sp.longestSpan() << std::endl; // Should throw NoSpanCanBeFound
    } catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 5: Empty span ===" << std::endl;
    try {
        Span sp = Span(5);
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl; // Should throw NoSpanCanBeFound
    } catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 6: Large span (10,000+ numbers) ===" << std::endl;
    try {
        Span sp = Span(10000);
        std::srand(std::time(0));
        
        for (int i = 0; i < 10000; ++i) {
            sp.addNumber(std::rand() % 100000);
        }
        
        std::cout << "Successfully stored 10,000 numbers" << std::endl;
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 7: Using addNumbers with vector iterators ===" << std::endl;
    try {
        Span sp = Span(10);
        std::vector<int> vec;
        vec.push_back(100);
        vec.push_back(200);
        vec.push_back(300);
        vec.push_back(400);
        vec.push_back(500);
        
        sp.addNumbers(vec.begin(), vec.end());
        sp.addNumber(600);
        
        sp.printNumbers();
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 8: addNumbers that would exceed capacity ===" << std::endl;
    try {
        Span sp = Span(5);
        std::vector<int> vec;
        for (int i = 0; i < 10; ++i) {
            vec.push_back(i);
        }
        
        sp.addNumbers(vec.begin(), vec.end()); // Should throw ThereIsNoSpaceLeft
    } catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 9: Negative numbers ===" << std::endl;
    try {
        Span sp = Span(5);
        sp.addNumber(-10);
        sp.addNumber(-5);
        sp.addNumber(0);
        sp.addNumber(5);
        sp.addNumber(10);
        
        sp.printNumbers();
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 10: Duplicate numbers ===" << std::endl;
    try {
        Span sp = Span(6);
        sp.addNumber(5);
        sp.addNumber(5);
        sp.addNumber(10);
        sp.addNumber(10);
        sp.addNumber(15);
        sp.addNumber(15);
        
        sp.printNumbers();
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 11: Very large numbers ===" << std::endl;
    try {
        Span sp = Span(4);
        sp.addNumber(1000000);
        sp.addNumber(2000000);
        sp.addNumber(3000000);
        sp.addNumber(4000000);
        
        sp.printNumbers();
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}