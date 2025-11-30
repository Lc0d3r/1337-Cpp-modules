#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include "easyfind.hpp"

int main() {
    std::cout << "=== Testing easyfind with vector ===" << std::endl;
    try {
        std::vector<int> vec;
        vec.push_back(1);
        vec.push_back(2);
        vec.push_back(3);
        vec.push_back(4);
        vec.push_back(5);
        
        // Test 1: Find existing element
        std::vector<int>::iterator it1 = easyfind(vec, 3);
        std::cout << "Found value 3 at position: " << std::distance(vec.begin(), it1) << std::endl;
        
        // Test 2: Find first element
        std::vector<int>::iterator it2 = easyfind(vec, 1);
        std::cout << "Found value 1 at position: " << std::distance(vec.begin(), it2) << std::endl;
        
        // Test 3: Find last element
        std::vector<int>::iterator it3 = easyfind(vec, 5);
        std::cout << "Found value 5 at position: " << std::distance(vec.begin(), it3) << std::endl;
        
        // Test 4: Try to find non-existing element
        std::vector<int>::iterator it4 = easyfind(vec, 42);
        std::cout << "Found value 42 at position: " << std::distance(vec.begin(), it4) << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    
    std::cout << "\n=== Testing easyfind with list ===" << std::endl;
    try {
        std::list<int> lst;
        lst.push_back(10);
        lst.push_back(20);
        lst.push_back(30);
        lst.push_back(20); // Duplicate value
        
        // Test 5: Find first occurrence
        std::list<int>::iterator it5 = easyfind(lst, 20);
        (void)it5; // Suppress unused variable warning
        std::cout << "Found value 20 (first occurrence)" << std::endl;
        
        // Test 6: Find another value
        std::list<int>::iterator it6 = easyfind(lst, 30);
        (void)it6; // Suppress unused variable warning
        std::cout << "Found value 30" << std::endl;
        
        // Test 7: Try to find non-existing element
        std::list<int>::iterator it7 = easyfind(lst, 100);
        (void)it7; // Suppress unused variable warning
        std::cout << "Found value 100" << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    
    std::cout << "\n=== Testing easyfind with deque ===" << std::endl;
    try {
        std::deque<int> deq;
        deq.push_back(100);
        deq.push_back(200);
        deq.push_back(300);
        
        // Test 8: Find existing element
        std::deque<int>::iterator it8 = easyfind(deq, 200);
        (void)it8; // Suppress unused variable warning
        std::cout << "Found value 200" << std::endl;
        
        // Test 9: Empty container
        std::deque<int> empty_deq;
        std::deque<int>::iterator it9 = easyfind(empty_deq, 42);
        (void)it9; // Suppress unused variable warning
        std::cout << "Found value in empty container" << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    
    std::cout << "\n=== Testing easyfind with single element container ===" << std::endl;
    try {
        std::vector<int> single;
        single.push_back(42);
        
        // Test 10: Find the only element
        std::vector<int>::iterator it10 = easyfind(single, 42);
        (void)it10; // Suppress unused variable warning
        std::cout << "Found value 42 in single-element container" << std::endl;
        
        // Test 11: Not found in single-element container
        std::vector<int>::iterator it11 = easyfind(single, 24);
        (void)it11; // Suppress unused variable warning
        std::cout << "Found value 24 in single-element container" << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    
    std::cout << "\n=== Testing easyfind with negative numbers ===" << std::endl;
    try {
        std::vector<int> negatives;
        negatives.push_back(-5);
        negatives.push_back(-3);
        negatives.push_back(-1);
        negatives.push_back(0);
        negatives.push_back(1);
        
        // Test 12: Find negative number
        std::vector<int>::iterator it12 = easyfind(negatives, -3);
        std::cout << "Found value -3 at position: " << std::distance(negatives.begin(), it12) << std::endl;
        
        // Test 13: Find zero
        std::vector<int>::iterator it13 = easyfind(negatives, 0);
        std::cout << "Found value 0 at position: " << std::distance(negatives.begin(), it13) << std::endl;
        
    } catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Testing easyfind with large container ===" << std::endl;
    try {
        std::vector<int> large;
        for (int i = 0; i < 1000; ++i) {
            large.push_back(i * 2);
        }
        
        // Test 14: Find in large container
        std::vector<int>::iterator it14 = easyfind(large, 500);
        std::cout << "Found value 500 at position: " << std::distance(large.begin(), it14) << " in large container" << std::endl;
        
        // Test 15: Not found in large container
        std::vector<int>::iterator it15 = easyfind(large, 501);
        (void)it15; // Suppress unused variable warning
        std::cout << "Found value 501 in large container" << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    
    return 0;
}