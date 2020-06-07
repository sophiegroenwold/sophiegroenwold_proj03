// intlist.cpp
// implements class IntList

#include "intlist.h"

#include <iostream>
using std::cout;

// copy constructor
IntList::IntList(const IntList& source) {
    Node* ptr = source.first;
    while (ptr)
    {
        this -> append(ptr -> info);
        ptr = ptr -> next;
    }
}

// destructor deletes all nodes
IntList::~IntList() {
    Node* a = first;
    Node* b = a;

    while (a)
    {
        a = a -> next;
        delete b;
        b = a;
    }

    first = 0;
}


// return sum of values in list
int IntList::sum() const {
    Node* ptr = first;
    int sum = 0;

    while (ptr)
    {
        sum += ptr -> info;
        ptr = ptr -> next;
    }
    
    return sum;
}

// returns true if value is in the list; false if not
bool IntList::contains(int value) const {
    Node* ptr = first;

    while (ptr)
    {
        if (ptr -> info == value)
            return true;
        ptr = ptr -> next;
    }

    return false;
}

// returns maximum value in list, or 0 if empty list
int IntList::max() const {
    Node* ptr = first;

    if (!ptr)
        return 0;

    int max = 0;

    while (ptr)
    {
        if (ptr -> info > max)
            max = ptr -> info;
        ptr = ptr -> next;
    }

    return max;
}

// returns average (arithmetic mean) of all values, or
// 0 if list is empty
double IntList::average() const {
    if (!first) return 0.0;
    double sum = this -> sum();
    double count = this -> count();
    return (sum / count);
}

// inserts value as new node at beginning of list
void IntList::insertFirst(int value) {
    Node* myNode = new Node();
    myNode -> info = value;
    myNode -> next = first;
    first = myNode;
}

//Assignment operator should copy the list from the source
//to this list, deleting/replacing any existing nodes
IntList& IntList::operator=(const IntList& source){
    // correct implementation:
    // Node* a = first;

    // while (a)
    // {
    //     a = a -> next;
    //     delete first;
    //     first = a;
    // }

    Node* a = first;
    Node* b = a;

    while (a)
    {
        a = a -> next;
        delete b;
        b = a;
    }

    Node* ptr = source.first;

    while (ptr)
    {   
        this -> append(ptr -> info);
        ptr = ptr -> next;
    }
    return *this;
}

// constructor sets up empty list
IntList::IntList() : first(0) { }

// append value at end of list
void IntList::append(int value) {
    if (first == 0) { // empty list
        first = new Node;
        first->info = value;
        first->next = 0;
    }
    else {
        Node *n = first;
        while (n->next) // not last node yet
            n = n->next;
        n->next = new Node;
        n->next->info = value;
        n->next->next = 0;
    }
}

// print values enclose in [], separated by spaces
void IntList::print() const {
    Node *n = first;
    cout << '[';
    while (n) {
        cout << n->info;
        if (n->next)
            cout << " ";
        n = n->next;
    }
    cout << ']';
}

// return count of values
int IntList::count() const {
    int result = 0;
    Node *n = first;
    while (n) {
        ++result;
        n = n->next;
    }
    return result;
}
