#include "list.h"
#include <iostream>
using namespace std;

// Constructor
template <typename Object>
List<Object>::List() {
    head = new Node;
    tail = new Node;
    head->next = tail;
    head->prev = nullptr;
    tail->prev = head;
    tail->next = nullptr;
    theSize = 0;
}

// Destructor
template <typename Object>
List<Object>::~List() {
    clear();
    delete head;
    delete tail;
}

//Helper function to find specific note through iteration
template <typename Object>
typename List<Object>::Node* List<Object>::find_node(int pos) const {
    if (pos < 0 || pos >= theSize)
        throw out_of_range("Index out of range");

    Node* p = head->next;
    while (pos--) p = p->next;
    return p;
}

// Prints out the size of list
template <typename Object>
int List<Object>::size() const {
    cout<<"The size of the linked list is: "<< theSize << endl;
    return theSize;
}

// Returns true if empty
template <typename Object>
bool List<Object>::empty() const {
    return theSize == 0;
}

// deletes all value in list
template <typename Object>
void List<Object>::clear() {
    Node* p = head->next;
    while (p != tail) {
        Node* t = p->next;
        cout<<"Clearing: "<<p->data<<endl;
        delete p;
        p = t;
    }
    head->next = tail;
    tail->prev = head;
    theSize = 0;
}

// Inserts value in front
template <typename Object>
void List<Object>::push_front(const Object& x) {
    cout << "Pushing to front: " << x << endl;
    Node* p = new Node;
    p->data = x;

    Node* first = head->next;
    p->next = first;
    p->prev = head;

    head->next = p;
    first->prev = p;

    ++theSize;
}

// Insert value in list
template <typename Object>
void List<Object>::push_back(const Object& x) {
    cout << "Pushing to back: " << x << endl;
    Node* p = new Node;
    p->data = x;

    Node* last = tail->prev;
    p->next = tail;
    p->prev = last;

    last->next = p;
    tail->prev = p;

    ++theSize;
}


// Deletes value in front of list
template <typename Object>
Object List<Object>::pop_front() {
    if (empty()) throw runtime_error("List is empty");
    Node* first = head->next;
    Object val = first->data;

    head->next = first->next;
    first->next->prev = head;

    delete first;
    --theSize;
    return val;
}

// Deletes the value in back of list
template <typename Object>
Object List<Object>::pop_back() {
    if (empty()) throw runtime_error("List is empty");
    Node* last = tail->prev;
    Object val = last->data;

    tail->prev = last->prev;
    last->prev->next = tail;

    delete last;
    --theSize;
    return val;
}

template <typename Object>
Object List<Object>::find_kth(int pos) const {
    return find_node(pos)->data;
}

template <typename Object>
void List<Object>::insert_kth(int pos, const Object& x) {
    if (pos < 0 || pos > theSize)
        throw out_of_range("Index out of range");

    Node* after;
    if (pos == theSize) {
        after = tail; 
    } else {
        after = find_node(pos);
    }

    Node* before = after->prev;

    Node* newNode = new Node;
    newNode->data = x;

    newNode->next = after;
    newNode->prev = before;
    before->next = newNode;
    after->prev = newNode;

    ++theSize;
}

template <typename Object>
void List<Object>::delete_kth(int pos) {
    if (pos < 0 || pos >= theSize) 
        throw out_of_range("Index out of range");

    // find the node to delete
    Node* target = head->next;
    for (int i = 0; i < pos; i++) {
        target = target->next;
    }

    // reconnect neighbors
    Node* before = target->prev;
    Node* after = target->next;

    before->next = after;
    after->prev = before;

    // delete target node
    delete target;

    --theSize;
}


template <typename Object>
void List<Object>::print_all() const {
    Node* p = head->next;
    while (p != tail) {
        cout << p->data << " -> ";
        p = p->next;
    }
    cout << endl;
}

template <typename Object>
void List<Object>::reverse() {
    Node* node = head; //Pointer to head of list(start).
    while (node != nullptr){
        swap(node->next,node->prev); //Swap memory addresses prev and next of each node thus reversing it
        node = node->prev; //Go to next node, note order is now reversed so to go to next node, go prev.
    }
    Node* node2 = tail; //Pointer to head of list(start).
    swap(node, node2); //Swap memory addresses head and tail, thus completing reversal of list.
}

template <typename Object>
bool List<Object>::contains(const Object& x) const {
    Node* p = head->next;
    while (p != tail) {
        if (p->data == x) return true; // found match
        p = p->next;
    }
    return false; // not found
}

template <typename Object>
void List<Object>::delete_element(const Object& x) {
    Node* target = head->next;

    while (target != tail) {
        if (target->data == x) {
            Node* before = target->prev;
            Node* after  = target->next;

            before->next = after;
            after->prev  = before;

            delete target;
            --theSize;

            break;
        }
        target = target->next;
    }
}

    