#include <iostream>
#include <vector>
#include <stdexcept>
#include <algorithm>
using namespace std;

template <typename T>
class MinHeap {
private:
    vector<T> heap; 
    
    // Helper index functions
    inline size_t leftChild(size_t i) { return 2 * i + 1; }
    inline size_t rightChild(size_t i) { return 2 * i + 2; }
    inline size_t parent(size_t i) { return (i - 1) / 2; }

    // Moves element at index i down to restore heap order property
    void percolateDown(size_t i) {
        size_t child;
        T tmp = move(heap[i]);  // store the current value

        // While we still have children to compare with
        while (leftChild(i) < heap.size()) {
            child = leftChild(i);

            // Choose the smaller child (to keep min-heap order)
            if (child + 1 < heap.size() && heap[child + 1] < heap[child]) {
                child++;
            }

            // If the smaller child is smaller than tmp, move it up
            if (heap[child] < tmp) {
                heap[i] = move(heap[child]);
            } else
                break;
        
            i = child;
        }

        heap[i] = move(tmp);
    }

    // As long as element i is greater than zero and our parent value above our child value is larger
    // Percolateup func swaps the newly added element with the parent element
    // until the parent is smaller and we have restored the minheap order.
    void percolateUp(size_t i) {
        while (i > 0 && heap[i] < heap[parent(i)]) {
            swap(heap[i], heap[parent(i)]);
            i = parent(i); 
        }
    }

public:
    MinHeap() = default;

    // Checks if the heap is emtpy
    bool isEmpty() const {
        if (heap.empty()) return true; //Use vector heap func to check if heap is empty. 
        return false;
    }

    // Adds a new element to the heap
    void insert(const T& x) {
        heap.push_back(x); //Insert new element to the vector back.
        percolateUp(heap.size() - 1); //We use perculate up to fix ordering, so smallest element is on top
    }

    // Returns the smallest element (root)
    const T& findMin() const {
        if (heap.empty())
            throw underflow_error("Heap is empty"); //If heap is empty we throw an error.
        return heap[0]; //Top element will always be min value, so we always return that. 
    }

    void deleteMin() { 
        if (heap.empty())
            throw underflow_error("Heap is empty");

        heap[0] = move(heap.back());   // deleteMin() removes the smallest element (the root) from the heap.
                                       // It replaces it with the last element which is heap.back(Very fast O(1) operation.) 
        heap.pop_back();               //Then we pop the heap.popback to make sure we dont have a duplicate heap.back element :)
        
        if (!heap.empty())
            percolateDown(0); //We use percolatedown to fix ordering of the heap, so smallest element is on top
    }

    //Helper for testing
    void printHeap() const {
        for (auto& val : heap) cout << val << " ";
        cout << endl;
    }
};

int main() {
    cout << "--- Priority Queue (MinHeap) test ---" << endl;

    MinHeap<int> pq;  // create MinHeap<int> instance

    // Insert some values
    pq.insert(5);
    pq.insert(3);
    pq.insert(8);
    pq.insert(1);

    cout << "Heap after inserts: ";
    pq.printHeap();

    // Delete the smallest element (the root)
    pq.deleteMin();
    pq.deleteMin();

    cout << "Heap after deleteMin(): ";
    pq.printHeap();

    pq.insert(2);
    pq.insert(7);
    pq.printHeap();

    return 0;
}
