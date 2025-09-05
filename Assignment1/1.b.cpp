// Write a program that generates M intergers and puts them in a vector. 
// Then generate another N random intergers and count how many of them are in the array using an iterator 

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;
// M = N because they are both arbitrarily large numbers that can range from 0 to infinity
// So when we look at N and M asymptotically, they are practically the same.

int main() {
    srand(time(nullptr));                   // O(1)

    int M = rand() % 11;                    // O(1)
    int N = rand() % 6;                     // O(1)

    vector<int> data;                       // O(1)

    for (int i = 0; i < M; i++) {           // O(N) iterations
        int num = rand() % 101;             // O(1) per iter
        data.push_back(num);                // O(1) per iter
    }

    cout << "Data vector (M numbers): ";    // O(1)
    for (int num : data) {                  // O(N)
        cout << num << " ";                 // O(1) per element
    }
    cout << endl;                           // O(1)

    int count = 0;                          // O(1)

    for (int i = 0; i < N; i++) {           // O(N)
        int num = rand() % 101;             // O(1)
        cout << "Generated N number: " << num << endl;  // O(1)

        for (auto it = data.begin(); it != data.end(); ++it)  // up to O(N)
        {
            if (*it == num) {                               // O(1)
                cout << "  Found a match: " << num << endl; // O(1)
                count++;                                    // O(1)
                break;                                      // O(1)
            }
        }
    }


cout << "The final count is: " << count << endl;        // O(1)
return 0;                                               // O(1)
}

// Total worst-case time: Θ(N) + Θ(N) + Θ(N·N) 
// Complexity: = T(N) = Θ(N·N) = Θ(N²) (Exponential growth dominates).

