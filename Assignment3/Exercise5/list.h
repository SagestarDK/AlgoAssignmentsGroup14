#pragma once

template <typename Object>
class List {
private:
    struct Node {
        Object data;
        Node* next;
        Node* prev;
    };

    int theSize;
    Node* head;
    Node* tail;
    Node* find_node(int pos) const;
    // Exercise5.cpp assignment 3
    int search_from(Node* node, const Object& x, int index) const;

public:
    List();
    ~List();

    int size() const;
    bool empty() const;

    void clear();
    void push_front(const Object& x);
    void push_back(const Object& x);

    Object pop_front();
    Object pop_back();

    Object find_kth(int pos) const;
    void insert_kth(int pos, const Object& x);
    void delete_kth(int pos);
    void print_all() const;
    void reverse();
    // Exercise5.cpp assignment 3
    int search(const Object& x) const;
};

#include "list.tpp"
