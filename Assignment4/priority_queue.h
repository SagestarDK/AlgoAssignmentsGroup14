#pragma once
#include <iostream>
#include "min_heap.h"

// Template so it works for any data type
template <typename T>
class MinHeapPriorityQueue {
private:
    MinHeap<T> heap;   

public:
    MinHeapPriorityQueue() = default;

    //Insert element into priority queue ---
    void insert(const T& value) {
        heap.insert(value);
    }

    //Return the smallest element ---
    const T& findMin() const {
        return heap.findMin();
    }

    //Remove the smallest element ---
    void deleteMin() {
        heap.deleteMin();
    }

    //Check if queue is empty ---
    bool isEmpty() const {
        return heap.isEmpty();
    }

    void printQueue() const {
        heap.printHeap();
    }
};
