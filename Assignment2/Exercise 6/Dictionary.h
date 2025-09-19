#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <vector>
#include <utility>   // for std::pair
#include <iostream>
using namespace std;

template <typename Key, typename Value>
class Dictionary {
private:
    vector<pair<Key, Value>> data;  // underlying storage: vector of (key, value) pairs

    //Findkey uses an iterator to traverse vector from begin(0) to data(n-1) 
    //and if it finds given key, it returns iterator to it. If not, it returns the end of the vector instead.

    // non-const version (for insert/remove)
    typename vector<pair<Key, Value>>::iterator findKey(const Key& k) {
        for (auto it = data.begin(); it != data.end(); ++it) {
            if (it->first == k) return it;
        }
        return data.end();
    }

    // const version (for contains/find)
    typename vector<pair<Key, Value>>::const_iterator findKey(const Key& k) const {
        for (auto it = data.begin(); it != data.end(); ++it) {
            if (it->first == k) return it;
        }
        return data.end();
    }

public:
    // --- Constructors / Destructor for dictionary. Handled automatically by the vector data structure we use, so we dont need to implement them ourselves.
    Dictionary() {}
    ~Dictionary() {}

    void insert(const Key& k, const Value& v) {
        // If key already exists, update its value
        // otherwise push_back a new pair
        auto it = findKey(k);
        if (it != data.end()) {
            cout << "Inserting specified pair" << endl;
            it->second = v;   // update
        } else {
            data.push_back(make_pair(k, v)); // add new
        }
    }

    bool remove(const Key& k) {
        //Use find  key to find iterator to given key, then erase that element if the key is found in the vector using vector 
        //.erase method and then return true to indicate we deleted it successfully. Otherwise return false.
        auto it = findKey(k);
        if (it != data.end()) {
            cout << "Erasing: " << k << endl;
            data.erase(it); 
            return true;   
        }
        return false;
    }

    Value* find_value(const Key& k) {
        //Use find key again to find iterator pointing to element in vector, then return value we are looking for(it second). 
        //Otherwise return a pointer to nothing. :)
        auto it = findKey(k);
        if (it != data.end()) {
            cout<<"Key found! Value is: "<<*it->second<<endl;
            return &it->second;
        } else {
            return nullptr;
        }
    }

    bool contains(const Key& k) const {
        //If key is in map, return true. 
        if (findKey(k) != data.end())
            cout << "The map is not empty" << endl;
        else 
            cout << "The map empty" << endl;
        return findKey(k) != data.end();
    }

    int size() const {
        //Return size of vector/map :)
        cout << "The size is: " << data.size() << endl;
        return data.size();
    }

    bool empty() const {
        //Return if vector is empty using provided .empty from vector library. 
        cout<<"Map is: "<< data.empty <<endl;
        return data.empty();
    }

    void clear() {
        //We use vector clear method to clear map.
        cout << "Map Cleared" << endl;
        data.clear();
    }

    void print() const {
        //Iterate through vector and print value at each element.
        cout << "Printing map: " << endl;
        for (auto it = data.begin(); it != data.end(); ++it) {
            cout << it->second << endl;
        }   
    }
};

#endif // DICTIONARY_H
