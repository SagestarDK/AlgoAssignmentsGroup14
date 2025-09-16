#ifndef SET_ADT_H
#define SET_ADT_H

#include "list.h"  // your List ADT from Assignment 2.1

// ===========================
// Set ADT (using List ADT)
// ===========================
template <typename T>
class Set {
private:
    List<T> list;   // underlying storage

public:
    // --- Constructors / Destructor ---
    Set() {
        // TODO: initialize empty set
    }

    ~Set() {
        // TODO: clean up memory if needed
    }

    // --- Core operations ---
    bool add(const T& x) {
        // TODO: if not in list, insert; else ignore
        if (list.contains(x)) {
            cout<<"Element already exists in set, no duplicates allowed!"<<endl;
            return false;
        } else {
            cout<<"Inserting element " << x << " in list"<<endl;
            list.push_front(x);
            return true;   
        }
    }

    bool remove(const T& x) {
        if (list.contains(x)) {
            cout<<"We have found: "<<x<< "in set, deleting it"<<endl;
            list.delete_element(x);
            return true;
        }
        else {
            cout << "We havent found x in set" << endl;
            return false;
        }
    }

    bool contains(const T& x) const {

        cout << "The set contains x" << endl;
        return list.contains(x);
    }

    int size() const {
        cout << "Size of set: " <<list.size()<<endl;
        return list.size();
    }

    bool isEmpty() const {
        cout << "Set is now empty" << endl;
        return list.empty();
    }

    void clear() {
        // TODO: remove all elements
        list.clear();
        cout << "Clearing set!" << endl;
    }

    void print() const {
        // TODO: traverse list and print
        list.print_all();
        cout << "prints set" << endl;
    }
};

#endif // SET_ADT_H
