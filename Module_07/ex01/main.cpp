#include <iostream>
#include <string>
#include "iter.hpp"

template <typename T>
void incrementElement(T& element) {
    ++element; 
}

void modifyString(std::string& str) {
    str += "_UPDATED";
}

template <typename T>
void printElement(const T& element) {
    std::cout << "[" << element << "] ";
}

int main() {
    
    // =======================================================
    // Test 1: int array (Modification and Display)
    // =======================================================
    std::cout << "--- Test 1: int array (Modification) ---" << std::endl;
    int intArray[] = {5, 15, 25, 35, 45};
    size_t intLength = 5;

    std::cout << "Initial intArray: ";
    ::iter(intArray, intLength, printElement<int>);
    std::cout << std::endl;

    // Call the templated function
    std::cout << "Applying incrementElement<int>..." << std::endl;
    ::iter(intArray, intLength, incrementElement<int>);

    std::cout << "Modified intArray (each element + 1): ";
    ::iter(intArray, intLength, printElement<int>);
    std::cout << "\n" << std::endl;
    
    // =======================================================
    // Test 2: std::string array (Modification)
    // =======================================================
    std::cout << "--- Test 2: std::string array (Modification) ---" << std::endl;
    std::string stringArray[] = {"one", "two", "three"};
    size_t stringLength = 3;
    
    std::cout << "Initial stringArray: ";
    ::iter(stringArray, stringLength, printElement<std::string>);
    std::cout << std::endl;

    // *** FIX: Now using the uniquely named 'modifyString' function ***
    // The compiler can now deduce F = 'void(*)(std::string&)' without ambiguity.
    std::cout << "Applying modifyString (unique name avoids cast)..." << std::endl;
    ::iter(stringArray, stringLength, modifyString);

    std::cout << "Modified stringArray: ";
    ::iter(stringArray, stringLength, printElement<std::string>);
    std::cout << "\n" << std::endl;

    // =======================================================
    // Test 3: const char* array (Const Display)
    // =======================================================
    std::cout << "--- Test 3: const char* array (Const Display) ---" << std::endl;
    const char* charArray[] = {"C++", "Module", "07"};
    size_t charLength = 3;

    std::cout << "const char* array: ";
    ::iter(charArray, charLength, printElement<const char*>); 
    std::cout << "\n" << std::endl;
    
    // =======================================================
    // Test 4: Edge Cases (Empty array and size 1 array)
    // =======================================================
    std::cout << "--- Test 4: Edge Cases ---" << std::endl;
    
    // 4a: Empty array (size 0)
    double emptyArray[] = {};
    size_t emptyLength = 0;
    std::cout << "4a) Empty array (no output expected): ";
    ::iter(emptyArray, emptyLength, printElement<double>);
    std::cout << "(Done)" << std::endl;
    
    // 4b: Array of size 1
    float singleFloat[] = {99.9f};
    size_t singleLength = 1;
    std::cout << "4b) Size 1 array: ";
    ::iter(singleFloat, singleLength, printElement<float>);
    std::cout << std::endl;

    return 0;
}