#include <iostream>
#include "priority_queue.h"
using namespace std;

int main() {
    cout << "--- MinHeapPriorityQueue Test ---" << endl;

    MinHeapPriorityQueue<int> pq;  


    pq.insert(10);
    pq.insert(5);
    pq.insert(3);
    pq.insert(8);

    cout << "Queue after inserts: ";
    pq.printQueue();

    cout << "Min element: " << pq.findMin() << endl;

    pq.deleteMin();
    cout << "After deleteMin: ";
    pq.printQueue();

    cout << "Min element: " << pq.findMin() << endl;


    cout << "Is empty? " << (pq.isEmpty() ? "Yes" : "No") << endl;

    return 0;
}
