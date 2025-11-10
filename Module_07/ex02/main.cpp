#include <iostream>
#include <string>
#include <cstdlib> // For EXIT_SUCCESS/EXIT_FAILURE
#include "Array.hpp" // Your Array class template

// A simple C++98 compatible custom class for testing generic types
class Awesome {
private:
    int _n;
public:
    Awesome() : _n(0) {}
    Awesome(int n) : _n(n) {}
    Awesome(const Awesome& other) : _n(other._n) {}
    
    // Allows the object to be printed with '<<'
    int get_n() const { return _n; }
    
    // Method to prove modification is possible
    void increment() { _n++; }
};

// Overload '<<' operator for the Awesome class for easy printing
std::ostream& operator<<(std::ostream& o, const Awesome& a) {
    o << "Awesome(" << a.get_n() << ")";
    return o;
}

// --- Main Test Function ---
int main() {
    
    // =======================================================
    // Test 1: Construction & Size
    // =======================================================
    std::cout << "--- Test 1: Construction & Size ---" << std::endl;
    
    // 1a: Default constructor (size 0)
    Array<int> empty_arr;
    std::cout << "1a) Empty Array size: " << empty_arr.size() << std::endl;

    // 1b: Size constructor (size 10)
    const unsigned int SIZE = 10;
    Array<float> float_arr(SIZE);
    std::cout << "1b) Float Array size: " << float_arr.size() << std::endl;

    // =======================================================
    // Test 2: Subscript Operator [] (Non-Const Access & Modification)
    // =======================================================
    std::cout << "\n--- Test 2: Subscript Operator [] (Modification) ---" << std::endl;
    
    // Initialize elements (tests non-const operator[])
    std::cout << "Initializing float_arr (0.0 to 9.0): ";
    for (unsigned int i = 0; i < SIZE; ++i) {
        float_arr[i] = (float)i;
        std::cout << float_arr[i] << " ";
    }
    std::cout << std::endl;
    
    // =======================================================
    // Test 3: Deep Copy (Copy Constructor & Assignment Operator)
    // =======================================================
    std::cout << "\n--- Test 3: Deep Copy ---" << std::endl;

    // 3a: Copy Constructor
    Array<float> copy_arr = float_arr;
    copy_arr[0] = 42.42f; // Modify copy_arr

    std::cout << "3a) Original float_arr[0]: " << float_arr[0] << std::endl; // Should be 0.0
    std::cout << "3a) Copy copy_arr[0]:      " << copy_arr[0] << std::endl;   // Should be 42.42
    
    // 3b: Assignment Operator
    Array<float> assign_arr(5); // Start with a different size
    assign_arr = float_arr;
    assign_arr[1] = 99.99f; // Modify assign_arr

    std::cout << "3b) Original float_arr[1]: " << float_arr[1] << std::endl; // Should be 1.0
    std::cout << "3b) Assign assign_arr[1]:  " << assign_arr[1] << std::endl;  // Should be 99.99
    
    // =======================================================
    // Test 4: Exception Handling (Out-of-Bounds Access)
    // =======================================================
    std::cout << "\n--- Test 4: Exception Handling ---" << std::endl;

    // Test 4a: Accessing an index too high
    try {
        std::cout << "4a) Trying to access float_arr[10] (out-of-bounds)..." << std::endl;
        float_arr[10] = 0.0f; // Index 10 for size 10 is OOB
        std::cout << "FAIL: Did not throw exception." << std::endl;
    }
    catch (std::exception& e) {
        std::cout << "SUCCESS: Caught exception: " << e.what() << std::endl;
    }
    catch (...) {
        std::cout << "SUCCESS: Caught unknown exception." << std::endl;
    }
    
    // Test 4b: Accessing an empty array
    try {
        std::cout << "4b) Trying to access empty_arr[0]..." << std::endl;
        empty_arr[0] = 1;
        std::cout << "FAIL: Did not throw exception." << std::endl;
    }
    catch (std::exception& e) {
        std::cout << "SUCCESS: Caught exception: " << e.what() << std::endl;
    }
    catch (...) {
        std::cout << "SUCCESS: Caught unknown exception." << std::endl;
    }

    // =======================================================
    // Test 5: Generic Type T (std::string and Custom Class)
    // =======================================================
    std::cout << "\n--- Test 5: Generic Types ---" << std::endl;

    // 5a: Test with std::string
    Array<std::string> str_arr(3);
    str_arr[0] = "Hello";
    str_arr[1] = "Templates";
    str_arr[2] = "World";
    std::cout << "5a) String Array: [" << str_arr[0] << ", " << str_arr[1] << ", " << str_arr[2] << "]" << std::endl;
    str_arr[1] = "Generic";
    std::cout << "5a) Modified String: [" << str_arr[1] << "]" << std::endl;

    // 5b: Test with Custom Class 'Awesome'
    Array<Awesome> awesome_arr(2);
    awesome_arr[0] = Awesome(42);
    awesome_arr[1] = Awesome(21);
    awesome_arr[0].increment(); // Modify custom object
    std::cout << "5b) Awesome Array: [" << awesome_arr[0] << ", " << awesome_arr[1] << "]" << std::endl;

    // =======================================================
    // Test 6: Const Correctness (Requires const operator[])
    // =======================================================
    std::cout << "\n--- Test 6: Const Correctness ---" << std::endl;
    
    const Array<float> const_arr = float_arr; // float_arr is size 10
    
    // Check reading via const operator[]
    std::cout << "6) Const Array access: " << const_arr[9] << std::endl; 
    
    // Test const access out-of-bounds
    try {
        std::cout << "6) Trying to access const_arr[10]..." << std::endl;
        std::cout << const_arr[10] << std::endl;
        std::cout << "FAIL: Did not throw exception." << std::endl;
    }
    catch (std::exception& e) {
        std::cout << "SUCCESS: Caught exception: " << e.what() << std::endl;
    }
    
    // NOTE: An attempt to modify a const array (e.g., const_arr[0] = 1.0f;) 
    // must be tested by checking if the compiler produces an error.
    // Uncomment the line below to check for a compile error (which it should!)
    // const_arr[0] = 1.0f; // <-- This MUST cause a compiler error

    return EXIT_SUCCESS;
}