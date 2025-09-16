#ifndef SET_ADT_H
#define SET_ADT_H

#include "List.h"   // reuse your linked list implementation from 2.1

// ===========================
// Set ADT (built on List ADT)
// ===========================
class Set {
private:
    List list;   // underlying storage for the Set

public:
    // --- Constructors / Destructor ---
    Set();   // TODO: initialize empty set
    ~Set();  // TODO: clean up memory

    // --- Core Set operations ---
    bool add(int x);
    // TODO: check if x already exists in list; if not, insert at end

    bool remove(int x);
    // TODO: find x in list, remove it if found, return success/fail

    bool contains(int x) const;
    // TODO: scan through list to see if x exists

    int size() const;
    // TODO: return number of elements (delegates to list.size())

    bool isEmpty() const;
    // TODO: return true if list is empty

    void clear();
    // TODO: remove all elements from list

    // --- Utility / Debug ---
    void print() const;
    // TODO: traverse list and print elements
};

#endif // SET_ADT_H
