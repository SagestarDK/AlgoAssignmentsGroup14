#ifndef QUEUE_CLASS_H
#define QUEUE_CLASS_H

#include "stack.hpp"

template <typename Object>
class Queue {
private:
    Stack<Object> s1;   //Stack

public:
    //Constructor
    Queue();

    //Destructor
    ~Queue();

    void enqueue(const Object& x);

    Object dequeue();

    Object front();

    bool empty();
};

// Template Definitions
// Constructor
template <typename Object>
Queue<Object>::Queue() {
    //Nothing to add here, s1 already has default constructor implemented
}

// Destructor
template <typename Object>
Queue<Object>::~Queue() {
    //Nothing to add here, s1 already has default destructor implemented in stack.
}

// Enqueue, push element onto queue. Here we use stack.push.
template <typename Object>
void Queue<Object>::enqueue(const Object& x) {
    s1.push(x); //push value onto stack
    cout<<"Element pushed into queue!"<<endl;
}

//Dequeue, here with use a recursive method to pop all elements on stack until we reach bottom element, which we pop and save as front element
//Then we recursively restore rest of the queue and return frontelement last.
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


// Front (recursive, single stack), do the same as dequeue expect here we do not pop the top element we return, we restore everything.
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


// Empty, use stack isEmpty function to return if empty.
template <typename Object>
bool Queue<Object>::empty() {
    return s1.isEmpty();
}


#endif // QUEUE_CLASS_H
