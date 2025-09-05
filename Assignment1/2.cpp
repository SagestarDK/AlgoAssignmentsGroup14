#include <iostream>

int myMethod(int N)
{
    int x = 0;                              // O(1)
    int y = 0;                              // O(1)
    
    // Triple-nested: N * N * (N*sqrt(N)) = N^3.5
    for (int i = 0; i < N; i++) {                       // O(N)
        for (int j = 0; j < N; j++) {                   // O(N)
            for (int k = 0; k < N * sqrt(N); k++) {     // O(N * sqrt(N))
                x++;                                    // O(1) pr. iteration
            }
        }
    }

    for (int i = 0; i < N * N; i++)         // O(N^2)
    {
        y++;                                // O(1) pr. iteration
    }

    return x + y;                           // O(1)
}
// Total = O(N*N*(N*sqrt(N)) + O(N*N) + 5*O(1)
// Complexity = O(N^3.5)