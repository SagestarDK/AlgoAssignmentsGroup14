// Write a program that generates M intergers and puts them in a vector. 
// Then generate another N random intergers and count how many of them are in the array using an iterator 

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    srand(time(nullptr));  // seed rng once at program start
    // Initiate M & N
    int M = rand() % 11;                  
    int N = rand() % 6;   

    vector<int> data;

    // Generate random numbers between 0 and 100 M times and store in array
    for (int i = 0; i < M; i++) {
        int num = rand() % 101;
        data.push_back(num);
    }

    cout << "Data vector (M numbers): ";
    for (int num : data) {
        cout << num << " ";
    }
    cout << endl;

    // Generate random numbers between 0 and 100 N time, then see if found in array
    int count = 0;

    for (int i = 0; i < N; i++) {
        int num = rand() % 101;
        cout << "Generated N number: " << num << endl;

        // compare these to numbers stored in array and count
        for (auto it = data.begin(); it != data.end(); ++it) {
            if (*it == num) {
                cout << "  Found a match: " << num << endl;
                count++;
                break;  // stop once we’ve found it (no duplicates)
            }
        }
    }

    // Print final count of numbers found
    cout << "The final count is: " << count << endl;

    return 0;
}


