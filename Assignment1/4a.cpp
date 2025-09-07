#include <iostream>
#include <vector>
#include <algorithm>   // max_element, distance
using namespace std;

class MaxHeap {
public:
    // is the heap empty?
    virtual bool isEmpty() const = 0;          // O(1)

    // number of elements in the heap
    virtual int size() const = 0;               // O(1)

    // add an element to the heap
    virtual void insert(const int x) = 0;       // amortized O(1); worst O(N) on reallocation

    // find the maximum element in the heap
    virtual int findMax() const = 0;            // O(N) in this vector-based design

    // delete and return the maximum element of the heap
    virtual int deleteMax() = 0;                // O(N): find max O(N) + erase shift O(N) => O(N)

    virtual ~MaxHeap() = default;               // O(1)
};

// Implementation

class VectorMaxHeap : public MaxHeap {
private:
    // Initialize vector
    vector<int> data;                           // stores all elements (space O(N))

public:
    // is the heap empty?
    bool isEmpty() const override {
        // Checks whether the vector has zero elements.
        // Note: no I/O side-effects here; just return the predicate.
        return data.empty();                    // O(1)
    }

    // number of elements in the heap
    int size() const override {
        // Returns current number of elements.
        cout << "The size of the MaxHeap is: " << data.size() << "\n"; // I/O (doesn't affect asymptotics)
        return static_cast<int>(data.size());   // O(1)
    }

    // add an element to the heap
    void insert(const int x) override {
        // Appends x at the end of the vector.
        data.push_back(x);                      // amortized O(1); worst O(N) on capacity growth
        cout << "Inserted value: " << x << "\n";
    }

    // find the maximum element in the heap
    int findMax() const override {
        // Throws if empty, otherwise scans to find the largest value.
        if (isEmpty()) throw runtime_error("empty heap");
        auto it  = max_element(data.begin(), data.end());   // linear scan O(N)
        int idx  = static_cast<int>(distance(data.begin(), it)); // O(1) for random-access iterators
        int val  = *it;                                     // O(1)
        cout << "[findMax] Max value " << val << " at index " << idx << "\n";
        return val;                                         // O(1)
    }

    // delete and return the maximum element of the heap
    int deleteMax() override {
        // Throws if empty; finds the max then erases it.
        if (isEmpty()) throw runtime_error("empty heap");
        auto it  = max_element(data.begin(), data.end());   // O(N)
        int idx  = static_cast<int>(distance(data.begin(), it)); // O(1)
        int val  = *it;                                     // O(1)
        cout << "[deleteMax] Removing value " << val << " at index " << idx << "\n";
        data.erase(it);                                     // O(N) shift of tail elements
        cout << "[deleteMax] Size after erase: " << data.size() << "\n";
        return val;                                         // O(1)
    }
};

int main() {
    VectorMaxHeap heap;

    // Insert three elements
    heap.insert(1);        // amortized O(1)
    heap.insert(2);        // amortized O(1)
    heap.insert(10);       // amortized O(1)

    // Query state
    cout << (heap.isEmpty() ? "The MaxHeap is empty\n" : "The MaxHeap is not empty\n"); // O(1)
    heap.size();           // O(1)

    // Read and remove maximums
    heap.findMax();        // O(N)
    heap.deleteMax();      // O(N)
    heap.findMax();        // O(N)

    return 0;              // O(1)
}

/*
Summary of complexities (this vector+scan implementation):
- isEmpty()  : O(1)
- size()     : O(1)
- insert(x)  : amortized O(1) (worst O(N) on reallocation)
- findMax()  : O(N)
- deleteMax(): O(N)

Total of the sequence in main with current heap size N: O(N) (dominated by findMax/deleteMax/findMax).
*/
