#ifndef QUEUE_CLASS_H
#define QUEUE_CLASS_H

#include "stack.hpp"

// Public methods you must implement:
//
// 1. enqueue(const Object& x)   // add element at the back (FIFO order)
// 2. dequeue()                  // remove and return the front element
// 3. front()                    // return the front element without removing
// 4. empty()                    // check if queue is empty

template <typename Object>
class Queue {
private:
    Stack<Object> s1;   // first stack
    Stack<Object> s2;   // second stack (if needed)

public:
    // TODO: constructor
    Queue();

    // TODO: destructor
    ~Queue();

    // TODO: enqueue
    void enqueue(const Object& x);

    // TODO: dequeue
    Object dequeue();

    // TODO: front
    Object front();

    // TODO: empty
    bool empty();
};

// Template Definitions
// Constructor
template <typename Object>
Queue<Object>::Queue() {
    //Nothing to add here, s1 already has default constructor
}

// Destructor
template <typename Object>
Queue<Object>::~Queue() {
    //Nothing to add here, s1 already has default destructor
}

// Enqueue
template <typename Object>
void Queue<Object>::enqueue(const Object& x) {
    s1.push(x); //push value onto stack
    cout<<"Element pushed into queue!"<<endl;
}

//Dequeue
template <typename Object>
Object Queue<Object>::dequeue() {
    if (s1.isEmpty()) {
        throw std::runtime_error("Queue is empty");
    }

    // Pop the top element
    Object topElement = s1.pop();

    // Base case: if stack is empty AFTER popping, this was the bottom element
    if (s1.isEmpty()) {
        return topElement; // don't recurse, just return it
    }

    // Recursive case: dig deeper
    Object frontElement = dequeue();

    // Restore popped element on the way back
    s1.push(topElement);

    return frontElement;
}


// Front (recursive, single stack)
template <typename Object>
Object Queue<Object>::front() {
    if (s1.empty()) {
        throw std::runtime_error("Queue is empty");
    }

    // Pop the top
    Object topElement = s1.pop();

    // Base case: if stack is now empty → this was the bottom element (front of queue)
    if (s1.empty()) {
        // Restore before returning
        s1.push(topElement);
        return topElement;
    }

    // Recursive case: dig deeper
    Object frontElement = front();

    // Restore
    s1.push(topElement);

    return frontElement;
}


// Empty
template <typename Object>
bool Queue<Object>::empty() {
    return s1.isEmpty();
}


#endif // QUEUE_CLASS_H
