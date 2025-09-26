#include <cstddef>  // std::size_t
#include <stdexcept>
#include <cassert>
#include "list.h"


int main() {
    List<int> L;
    L.push_back(10);
    L.push_back(20);
    L.push_back(30);

    std::cout << "search(10) = " << L.search(10) << "\n"; // expect 0
    std::cout << "search(30) = " << L.search(30) << "\n"; // expect 2
    std::cout << "search(99) = " << L.search(99) << "\n"; // expect -1
}

