#include <iostream>
#include "Dictionary.h"

int main() {
    Dictionary<string, int> dict;

    dict.insert("apple", 3);
    dict.insert("banana", 5);
    dict.insert("orange", 7);

    dict.print(); // should show all key-value pairs

    if (dict.contains("banana")) {
        cout << "Banana exists!" << endl;
    }

    dict.remove("apple");
    dict.print();

    return 0;
}
