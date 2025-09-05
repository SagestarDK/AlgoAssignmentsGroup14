#include <stdio.h>
#include <time.h>

int main(void) {
    int N = 10000;   // N value
    volatile int sum = 0;

    clock_t start = clock();
    for (int i = 0; i < N; i++) { // O(N)
        ++sum;
    }
    clock_t end = clock();

    double duration = (double)(end - start) / CLOCKS_PER_SEC;
    printf("O(N), N=%d, sum=%d, time=%.6f s\n", N, sum, duration);
    return 0;
}

// Time complexity = O(N)