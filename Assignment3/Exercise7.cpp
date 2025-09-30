// exercise7.cpp
#include <iostream>
#include <vector>
#include <algorithm> 
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

int main() {
    // Test 1: empty
    std::vector<int> t1;
    std::cout << "=== empty ===\nbefore: [";
    for (size_t i=0;i<t1.size();++i) std::cout<<t1[i]<<(i+1<t1.size()? ", ":"");
    std::cout << "]\n";
    countingSort(t1);
    std::cout << "after : [";
    for (size_t i=0;i<t1.size();++i) std::cout<<t1[i]<<(i+1<t1.size()? ", ":"");
    std::cout << "]\n\n";

    // Test 2: small range with duplicates (k<=3)
    std::vector<int> t2 = {0,1,0,2,1,2,2,0,3,3,1};
    std::cout << "=== small range, duplicates (k<=3) ===\nbefore: [";
    for (size_t i=0;i<t2.size();++i) std::cout<<t2[i]<<(i+1<t2.size()? ", ":"");
    std::cout << "]\n";
    countingSort(t2);
    std::cout << "after : [";
    for (size_t i=0;i<t2.size();++i) std::cout<<t2[i]<<(i+1<t2.size()? ", ":"");
    std::cout << "]\n\n";

    // Test 3: wide range (k=1000)
    std::vector<int> t3 = {1000,0,999,1,500,500,2,3,3,10,999,1000,42,17,17,0,1,2,3,4};
    std::cout << "=== wide range (k=1000) ===\nbefore: [";
    for (size_t i=0;i<t3.size();++i) std::cout<<t3[i]<<(i+1<t3.size()? ", ":"");
    std::cout << "]\n";
    countingSort(t3);
    std::cout << "after : [";
    for (size_t i=0;i<t3.size();++i) std::cout<<t3[i]<<(i+1<t3.size()? ", ":"");
    std::cout << "]\n\n";

    return 0;
}
