#include <iostream>
#include <list>
#include <vector>
#include "MutantStack.hpp"

int main() {
    std::cout << "=== Test 1: Basic functionality from subject ===" << std::endl;
    {
        MutantStack<int> mstack;
        
        mstack.push(5);
        mstack.push(17);
        
        std::cout << mstack.top() << std::endl;
        
        mstack.pop();
        
        std::cout << mstack.size() << std::endl;
        
        mstack.push(3);
        mstack.push(5);
        mstack.push(737);
        mstack.push(0);
        
        MutantStack<int>::iterator it = mstack.begin();
        MutantStack<int>::iterator ite = mstack.end();
        
        ++it;
        --it;
        while (it != ite) {
            std::cout << *it << std::endl;
            ++it;
        }
        std::stack<int> s(mstack);
    }

    std::cout << "\n=== Test 2: Compare with std::list (as suggested in subject) ===" << std::endl;
    {
        std::cout << "Using MutantStack:" << std::endl;
        MutantStack<int> mstack;
        mstack.push(5);
        mstack.push(17);
        mstack.push(3);
        mstack.push(5);
        mstack.push(737);
        mstack.push(0);
        
        MutantStack<int>::iterator it = mstack.begin();
        MutantStack<int>::iterator ite = mstack.end();
        while (it != ite) {
            std::cout << *it << std::endl;
            ++it;
        }
        
        std::cout << "Using std::list:" << std::endl;
        std::list<int> lst;
        lst.push_back(5);
        lst.push_back(17);
        lst.push_back(3);
        lst.push_back(5);
        lst.push_back(737);
        lst.push_back(0);
        
        std::list<int>::iterator lit = lst.begin();
        std::list<int>::iterator lite = lst.end();
        while (lit != lite) {
            std::cout << *lit << std::endl;
            ++lit;
        }
    }

    std::cout << "\n=== Test 3: Reverse iteration ===" << std::endl;
    {
        MutantStack<int> mstack;
        mstack.push(1);
        mstack.push(2);
        mstack.push(3);
        mstack.push(4);
        mstack.push(5);
        
        std::cout << "Forward: ";
        for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it) {
            std::cout << *it << " ";
        }
        std::cout << std::endl;
        
        std::cout << "Reverse: ";
        for (MutantStack<int>::reverse_iterator it = mstack.rbegin(); it != mstack.rend(); ++it) {
            std::cout << *it << " ";
        }
        std::cout << std::endl;
    }

    std::cout << "\n=== Test 4: Const iteration ===" << std::endl;
    {
        MutantStack<int> mstack;
        mstack.push(10);
        mstack.push(20);
        mstack.push(30);
        
        const MutantStack<int>& const_mstack = mstack;
        
        std::cout << "Const iteration: ";
        for (MutantStack<int>::const_iterator it = const_mstack.begin(); it != const_mstack.end(); ++it) {
            std::cout << *it << " ";
            // *it = 100; // This would cause compilation error (good!)
        }
        std::cout << std::endl;
    }

    std::cout << "\n=== Test 5: String MutantStack ===" << std::endl;
    {
        MutantStack<std::string> stringStack;
        stringStack.push("Hello");
        stringStack.push("World");
        stringStack.push("from");
        stringStack.push("MutantStack");
        
        std::cout << "Strings: ";
        for (MutantStack<std::string>::iterator it = stringStack.begin(); it != stringStack.end(); ++it) {
            std::cout << *it << " ";
        }
        std::cout << std::endl;
    }

    std::cout << "\n=== Test 6: Copy constructor and assignment ===" << std::endl;
    {
        MutantStack<int> original;
        original.push(1);
        original.push(2);
        original.push(3);
        
        MutantStack<int> copy(original);
        MutantStack<int> assigned;
        assigned = original;
        
        std::cout << "Original: ";
        for (MutantStack<int>::iterator it = original.begin(); it != original.end(); ++it) {
            std::cout << *it << " ";
        }
        std::cout << std::endl;
        
        std::cout << "Copy: ";
        for (MutantStack<int>::iterator it = copy.begin(); it != copy.end(); ++it) {
            std::cout << *it << " ";
        }
        std::cout << std::endl;
        
        std::cout << "Assigned: ";
        for (MutantStack<int>::iterator it = assigned.begin(); it != assigned.end(); ++it) {
            std::cout << *it << " ";
        }
        std::cout << std::endl;
    }

    std::cout << "\n=== Test 7: Empty stack iteration ===" << std::endl;
    {
        MutantStack<int> emptyStack;
        
        std::cout << "Empty stack iteration (should print nothing): ";
        for (MutantStack<int>::iterator it = emptyStack.begin(); it != emptyStack.end(); ++it) {
            std::cout << *it << " ";
        }
        std::cout << "Done" << std::endl;
    }

    std::cout << "\n=== Test 8: Modification through iterators ===" << std::endl;
    {
        MutantStack<int> mstack;
        mstack.push(1);
        mstack.push(2);
        mstack.push(3);
        
        std::cout << "Before modification: ";
        for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it) {
            std::cout << *it << " ";
        }
        std::cout << std::endl;
        
        // Modify through iterator
        MutantStack<int>::iterator it = mstack.begin();
        *it = 100;
        ++it;
        *it = 200;
        
        std::cout << "After modification: ";
        for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it) {
            std::cout << *it << " ";
        }
        std::cout << std::endl;
    }

    std::cout << "\n=== Test 9: Large stack ===" << std::endl;
    {
        MutantStack<int> largeStack;
        for (int i = 0; i < 1000; ++i) {
            largeStack.push(i);
        }
        
        std::cout << "Size: " << largeStack.size() << std::endl;
        std::cout << "First element: " << *largeStack.begin() << std::endl;
        std::cout << "Last element: " << *(--largeStack.end()) << std::endl;
    }

    return 0;
}