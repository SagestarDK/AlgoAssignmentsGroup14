#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <vector>
#include <utility>   // for std::pair
#include <iostream>
using namespace std;

template <typename Key, typename Value>
class Dictionary {
private:
    vector<pair<Key, Value>> data;  
    // underlying storage: vector of (key, value) pairs

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
    // --- Constructors / Destructor ---
    Dictionary() {}
    ~Dictionary() {}

    // --- Core operations ---
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
        auto it = findKey(k);
        if (it != data.end()) {
            cout << "Erasing: " << k << endl;
            data.erase(it); 
            return true;   
        }
        return false;
    }

    Value* find_value(const Key& k) {
        auto it = findKey(k);
        if (it != data.end()) {
            cout<<"Key found! Value is: "<<*it->second<<endl;
            return &it->second;
        } else {
            return nullptr;
        }
    }

    bool contains(const Key& k) const {
        if (findKey(k) != data.end())
            cout << "The map is not empty" << endl;
        else 
            cout << "The map empty" << endl;
        return findKey(k) != data.end();
    }

    int size() const {
        cout << "The size is: " << data.size() << endl;
        return data.size();
    }

    bool empty() const {
        cout<<"Map is: "<< data.empty <<endl;
        return data.empty();
    }

    void clear() {
        cout << "Map Cleared" << endl;
        data.clear();
    }

    void print() const {
        cout << "Printing map: " << endl;
        for (auto it = data.begin(); it != data.end(); ++it) {
            cout << it->second << endl;
        }   
    }
};

#endif // DICTIONARY_H
