#include <iostream>
#include "intro_sort.h"
#include "insertion_sort.h"
#include "quick_sort.h"
#include <chrono>
using namespace std::chrono;


int main() {
    std::vector<int> v{7,3,9,1,5,4,8,2,6};
    introSort(v);
    for (auto x : v) std::cout << x << ' ';
    std::cout << '\n';

    std::vector<int> v2{7,3,9,1,5,4,8,2,6};
    introSort(v2);
    for (auto x : v2) std::cout << x << ' ';
    std::cout << '\n';
}