#include <iostream>
#include "Set.h"
using namespace std;

int main() {
    Set<int> s;

    // TODO: test all functions
    cout << "Is empty? " << s.isEmpty() << endl;

    s.add(5);
    s.add(10);
    s.add(5); // duplicate, should be ignored

    cout << "Contains 10? " << s.contains(10) << endl;
    cout << "Contains 7? " << s.contains(7) << endl;

    s.print();

    s.remove(10);
    s.print();

    cout << "Size = " << s.size() << endl;

    s.clear();
    s.isEmpty();
    return 0;
}
