// intlist.h
// Linked list header file 

#ifndef INTLIST_H
#define INTLIST_H

class IntList {

public:

    // constructor and 3 methods already done in intlist.cpp (NO CHANGE):
    IntList();              // constructor
    void append(int value); // append value at end of list
    void print() const;     // print values separate by ' '
    int count() const;      // return count of values

    // destructor, copy constructor and 6 other methods
    ~IntList();                      // destructor
    IntList(const IntList& source); //copy constructor (deep copy)
    int sum() const;                 // sum of all values
    bool contains(int value) const;  // true if value in list
    int max() const;                 // maximum value
    double average() const;          // average of all values
    void insertFirst(int value);     // insert new first value

    IntList& operator=(const IntList& source); //overloaded

private:

    // definition of Node structure
    struct Node {
        int info;
        Node *next;
    };

    Node *first; // pointer to first node
};

#endif
