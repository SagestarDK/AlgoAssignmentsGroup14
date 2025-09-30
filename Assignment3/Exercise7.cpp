// exercise7.cpp
#include <iostream>
#include <vector>
#include <algorithm> // for std::max if needed
using namespace std;

// TODO: implement countingSort function
void countingSort(std::vector<int> &a) {
    if (a.empty()) return;  // edge case: nothing to sort

    // 1. Find max value (range of keys)
    int maxVal = *std::max_element(a.begin(), a.end());

    // 2. Create count array (size = maxVal+1), initialize to 0
    std::vector<int> count(maxVal + 1, 0);

    // 3. Count frequency of each element
    for (int num : a) {
        count[num]++;
    }

    // 4. Prefix sum (so count[i] = position after last occurrence of i)
    for (int i = 1; i <= maxVal; i++) {
        count[i] += count[i - 1];
    }

    // 5. Create output array of same size as input
    std::vector<int> output(a.size());

    // 6. Place elements into output (stable, go backwards)
    for (int i = (int)a.size() - 1; i >= 0; i--) {
        int num = a[i];
        count[num]--;
        output[count[num]] = num;
    }

    // 7. Copy back into a
    a = std::move(output);
}

//  - find the maximum value (k) in the array
//  - create a count array of size k+1
//  - count how many times each number appears
//  - rebuild the sorted array from the counts

int main() {
    // TODO: create test vectors with integers in range [0..k]

    // TODO: print vector before sorting

    // TODO: call countingSort on the vector

    // TODO: print vector after sorting

    // TODO: add more test cases with different ranges of k
}
