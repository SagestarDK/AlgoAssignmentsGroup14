// exercise6.cpp
#include <iostream>
#include <vector>
#include <string>   // for std::string in test data
#include <utility>  // for std::swap

// Selection Sort (generic template).
// Repeatedly finds the minimum element in the unsorted suffix [i..n-1]
// and swaps it with the element at position i.
// - Time: Θ(N^2) comparisons in all cases; up to N-1 swaps.
// - Space: O(1) extra (in-place).
// - Stability: Not stable.
template <typename T>
void selectionSort(std::vector<T> &a){
        // Outer loop grows the sorted prefix [0..i-1].
    for (int i = 0; i < a.size()-1; i++)
    {   
        int minIndex = i;   // index of the smallest element in [i..end)

        // Scan the unsorted suffix to find the global minimum.
        for (int j = i + 1; j < a.size(); j++)
        {
            if(a[j] < a[minIndex]){
                minIndex = j;
            }
        }
        // Only swap if we actually found a smaller element.
        if (minIndex != i) {
            std::swap(a[i], a[minIndex]);
        }
    }
}

template <typename T>
void print_vec(const std::vector<T>& v) {
    for (const auto& x : v) std::cout << x << ' ';
    std::cout << '\n';
}

int main() {
    // Test 1: integers
    std::vector<int> a{7, 8, 2, 5, 1};
    std::cout << "Original a: "; print_vec(a);
    selectionSort(a);
    std::cout << "Sorted   a: "; print_vec(a);

    // Test 2: chars (will sort by character code / lexicographic order)
    std::vector<char> b{'a', 'h', '0', '2', 'c'};
    std::cout << "Original b: "; print_vec(b);
    selectionSort(b);
    std::cout << "Sorted   b: "; print_vec(b);

    // Test 3: negative integers
    std::vector<int> c{-12, -32, -39, -1, -9};
    std::cout << "Original c: "; print_vec(c);
    selectionSort(c);
    std::cout << "Sorted   c: "; print_vec(c);

    // Test 4: strings (lexicographic order)
    std::vector<std::string> d{"pear", "apple", "banana", "otto", "patrick", "jonas", "magnus", "abel"};
    std::cout << "Original d: "; print_vec(d);
    selectionSort(d);
    std::cout << "Sorted   d: "; print_vec(d);
}