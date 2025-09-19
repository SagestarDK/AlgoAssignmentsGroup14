#ifndef STACK_HPP
#define STACK_HPP

#include <iostream>
using namespace std;

template <typename T>
class Stack {
private:
    T* arr;          // pointer to dynamic array
    int cap;         // current capacity
    int topIndex;    // index of top element (-1 if empty)

public:
    Stack(int size);

    Stack();

    ~Stack();

    void push(const T& value);

    T pop();

    T top();

    bool isEmpty();

    int size();

    int capacity();
};

// Template Definitions

// Constructor with size
template <typename T>
Stack<T>::Stack(int size) {
    T* newArr = new T[size]; //Allocate dynamic array with given sizen when called.
    arr = newArr; //set arr pointer points to first element of array. Used to keep track of and access stack. 
    topIndex = -1; //Initialise top index and set to 0 as default.
    cout<<"DEBUG: Stack created with size: ."<<size<<endl;
}

// Default constructor
template <typename T>
Stack<T>::Stack() {
    T* newArr = new T[100]; // Allocate dynamic array with size 100.
    cap = 100; // Set capacity of stack to 100. 
    arr = newArr; // arr pointer points to first element of array and used to keep track of and access stack. 
    topIndex = -1; // Initialise top index and set to 0 as default.
    cout<<"DEBUG: Stack created."<<endl;
}

// Destructor
template <typename T>
Stack<T>::~Stack() {
    delete[] arr; // Delete stack array and free memory.
}

// push
template <typename T>
void Stack<T>::push(const T& value) { // Push worst case costs O(N) because we have
                                      // for loop that loops through whole array from 0...N
    cout<<"DEBUG: Pushing stack values onto stack."<<endl;
    if (cap == topIndex+1){ // If stack is full
        cout<<"DEBUG: Stack is full."<<endl;
        T* newArr = new T[cap * 2]; // Create new resized stack array equal to old one with twice the size.

        for(int i = 0; i<=topIndex; i++){ // Loop through old array and copy all elements from that over to new resized one. 
            newArr[i] = arr[i]; 
        }

        delete[] arr; // Delete old array and free memory

        // Update pointer to array and capacity counter for array
        cout<<"DEBUG: Updating stack pointer and cap for array"<<endl;
        arr = newArr;
        topIndex = cap - 1; // Update topindex to be top of updated array.
        cap = cap * 2; // update new cap to be twice as big.

        // Push value on top of index
        topIndex++;
        arr[topIndex] = value; 
    }
    else{ // If stack isnt full, put value on top of stack.
        cout<<"DEBUG: Stack isnt full, pushing: "<<value<<endl;
        topIndex++;
        arr[topIndex] = value; 
    }
}

// pop
template <typename T>
T Stack<T>::pop() {
    if (isEmpty()){ // Is empty call only costs O(1) since is empty only calls topIndex to see if stack is empty.
        cout<<"Stack is empty"<<endl;
        return 0; 
    } else{
        T value = this->top();  // Get value at top using top method. 
                                // Costs O(1) since we only have basic print statements and again use isEmpty in top, which is O(1).
        cout<<"Stack is not empty, popping: "<<value<<endl; 
        topIndex--; // Decrement top index  
        return value; // return top value found. 
    }
}

// top
template <typename T>
T Stack<T>::top() {
    // Return top if stack isnt empty.
    if (isEmpty()){
        cout<<"Stack is empty"<<endl; 
        return 0; 
    } else{
        cout<<"Returning value: "<<arr[topIndex]<<" at element: "<<topIndex<<endl;
        return arr[topIndex];
    }
}

// isEmpty
template <typename T>
bool Stack<T>::isEmpty() {
    // If topindex is -1, stack is empty, return true then otherwise false.
    if(topIndex == -1){
        return true; 
    }
    else{
        return false; 
    }
}

// size
template <typename T>
int Stack<T>::size() {
    cout<<"DEBUG: Number of elemnents inside stack is: "<<topIndex+1<<endl;
    return topIndex+1; // return number of elements inside stack
}

// capacity
template <typename T>
int Stack<T>::capacity() {
    cout<<"DEBUG: Current cap is: "<<cap<<endl;
    return cap; // Return current capacity of stack
}

#endif // STACK_HPP

