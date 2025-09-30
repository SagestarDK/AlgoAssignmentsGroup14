#include <algorithm>
#include <iostream>
#include <vector>
#include <chrono>
using namespace std::chrono;
using namespace std;

int main() {
   vector<int> v(1000);

    // Generate Random values
    auto f = []() -> int { return rand() % 100; };

    // Fill up the vector
    generate(v.begin(), v.end(), f);

    // Get starting timepoint
    auto start = high_resolution_clock::now();

    // Call the function, here sort()
    sort(v.begin(), v.end());
    
    // Get ending timepoint
    auto stop = high_resolution_clock::now();

    // Get duration. Substart timepoints to 
    // get duration. To cast it to proper unit
    // use duration cast method
    auto duration = duration_cast<nanoseconds>(stop - start);

    cout << "Time taken by function: "
         << duration.count() << " nanoseconds" << endl;

    return 0;
}