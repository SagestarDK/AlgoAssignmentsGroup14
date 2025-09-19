#include "list.h"
#include <iostream>
using namespace std;

// Constructor
template <typename Object>
List<Object>::List() {
    head = new Node; 
    tail = new Node;
    head->next = tail; //Initialise head and tail, so we have head in front, pointing at tail in the back, ready for nodes to be added to our linked list.
    head->prev = nullptr;
    tail->prev = head;
    tail->next = nullptr;
    theSize = 0; //Set size variable to be 0 by default, when initialising list. 
}

// Destructor
template <typename Object>
List<Object>::~List() {
    clear();  //Call our clear function to clear out our list before we finally delete our head and tail nodes and thus delete our list after.
    delete head;
    delete tail;
}

//Helper function to find specific note through iteration
template <typename Object>
typename List<Object>::Node* List<Object>::find_node(int pos) const {
    //First we check if our given pos is within our list range, if yes then we set p to be first node after head
    //Then loop through pos times through our list and return node at given position. 
    if (pos < 0 || pos >= theSize)
        throw out_of_range("Index out of range");

    Node* p = head->next;
    while (pos--) p = p->next;
    return p;
}


template <typename Object>
int List<Object>::size() const { //We return our int theSize variable which contaon linked list size.
    cout<<"The size of the linked list is: "<< theSize << endl;
    return theSize;
}

template <typename Object>
bool List<Object>::empty() const { //We return boolean statement, if size=0 then list is empty and true is returned, if not empty is returned and list is "in use".
    return theSize == 0;
}

template <typename Object>
void List<Object>::clear() {
    //Clear method which clears all nodes from list beside head and tail.
    //It does this by setting p to be first node after head, then loop through list, save node after p in t, then delete node p is set to and repeat.
    //When done set head and tail to point to each other.
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

template <typename Object>
void List<Object>::push_front(const Object& x) {
    //We push value x to front by creating new node P with x data value, 
    //then pushing p to be "between" head and previous node in front first. Last we update size because we added new node to list.
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

template <typename Object>
void List<Object>::push_back(const Object& x) {
    //We push value x to back by creating new node P with x data value, 
    //then pushing p to be "between" previous node in back(node last) and the tail. Last we update size because we added new node to list.
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

template <typename Object>
Object List<Object>::pop_front() {
    //If list if not empty, then we create node first and set it to be equal to node after head and object val to be equal to that nodes' data. 
    //Then we set head to point to node after first and the node after first prev to point to head instead of first, 
    //then we delete first, decrement size and return val.
    if (empty()) throw runtime_error("List is empty");
    Node* first = head->next;
    Object val = first->data;

    head->next = first->next;
    first->next->prev = head;

    delete first;
    --theSize;
    return val;
}

template <typename Object>
Object List<Object>::pop_back() {
    //If list if not empty, then we create node last and set it to be equal to node before tail and object val to be equal to that nodes' data. 
    //Then we set tail to point to node before last and the node before last next to point to tail instead of last, 
    //then we delete last node, decrement size and return val.
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
    //We use find_node to find node indicated by pos and then return data from that specific node. 
    return find_node(pos)->data;
}

template <typename Object>
void List<Object>::insert_kth(int pos, const Object& x) {
    //First we make sure pos is within list range, then we create after node, if pos equal to size then we set it be be equal to tail node, 
    //otherwise we find node by using helperfunc find node. Then we initiate before node to be the node before after. Then we initialise a new node and set its data to be equal to x.
    //Finally we put this new node to be between before and after node, thus inserting it into kth position.
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
    //We follow same process as insert kth, expect here we delete the node between before and after instead of inserting a new node with data there.
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
    //Loop through whole list, print all nodes data.
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

