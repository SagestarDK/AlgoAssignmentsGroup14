#ifndef SET_ADT_H
#define SET_ADT_H

#include "list.h"  // We are building the Set ADT on top of the List ADT from Assignment 2.1

// Set ADT (using List ADT)
// ===========================
// A set is a collection of unique elements (no duplicates).
// This implementation uses the List ADT as the underlying storage.
template <typename T>
class Set {
private:
    List<T> list;   // The set internally uses a List to store elements

public:
    // --- Constructors / Destructor ---
    Set() {}        // Default constructor
    ~Set() {}       // Destructor (no special cleanup needed because List handles its own memory)

    // --- Core operations ---
    // Add an element to the set if it does not already exist
    bool add(const T& x) {
        if (list.contains(x)) { // Check if the element is already in the set
            cout<<"Element already exists in set, no duplicates allowed!"<<endl;
            return false;       // Do not insert duplicates
        } else {
            cout<<"Inserting element " << x << " in list"<<endl;
            list.push_front(x); // Insert new element at the front of the list
            return true;   
        }
    }

    // Remove an element from the set if it exists
    bool remove(const T& x) {
        if (list.contains(x)) { // Check if the element exists before removing
            cout<<"We have found: "<<x<< " in set, deleting it"<<endl;
            list.delete_element(x); // Remove the element from the list
            return true;
        }
        else {
            cout << "We havent found x in set" << endl;
            return false; // Element not found
        }
    }

    // Check if an element exists in the set
    bool contains(const T& x) const {
        cout << "The set contains x" << endl;
        return list.contains(x); // Delegates the check to the List ADT
    }

    // Return the number of elements in the set
    int size() const {
        cout << "Size of set: " <<list.size()<<endl;
        return list.size();
    }

    // Check if the set is empty
    bool isEmpty() const {
        cout << "Set is now empty" << endl;
        return list.empty();
    }

    // Remove all elements from the set
    void clear() {
        list.clear();
        cout << "Clearing set!" << endl;
    }

    // Print all elements in the set
    void print() const {
        list.print_all(); // Print function from the List ADT
        cout << "prints set" << endl;
    }
};

#endif // SET_ADT_H
