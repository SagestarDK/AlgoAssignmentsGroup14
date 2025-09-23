#include <iostream>
#include <stdexcept>
using namespace std;

// Helper function to print stars on line. When done prints new line ready for next function call.
void print_star(int k) {
    for (int i = 0; i < k; ++i) {
        cout << '*';
    }
    cout << '\n';
}

void triangle(int m, int n) {
    // Base case: must be non-negative and if n = m, we print 2 lines of n stars
    if (m < 0 || n < 0) throw invalid_argument("m and n must be non-negative");

    if (n == m) {
        print_star(n); 
        print_star(n);      
        return;
    }

    // Recursive step: Print m stars and call function again, once base case is hit, 
    // recurse back and print n-1 stars until m is reached
    print_star(m);       
    triangle(m + 1, n);
    print_star(m);         
}

int main() {
    triangle(3, 5);
}