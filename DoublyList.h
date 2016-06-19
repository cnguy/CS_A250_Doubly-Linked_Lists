#ifndef DOUBLYLIST_H
#define DOUBLYLIST_H

#include <string>
#include <iostream>

using namespace std;

class Node {
public:
    Node() : data(0), _next(nullptr), _prev(nullptr) { }

    Node(int newData, Node *newPrev, Node *newNext)
            : data(newData), _next(newNext), _prev(newPrev) { }

    Node *getNext() const { return _next; }

    Node *getPrev() const { return _prev; }

    int getData() const { return data; }

    void setData(int newData) { data = newData; }

    void setNext(Node *newNext) { _next = newNext; }

    void setPrev(Node *newPrev) { _prev = newPrev; }

    ~Node() { }

private:
    int data;
    Node *_next;
    Node *_prev;
};


class DoublyList {
public:
    // constructor
    DoublyList();

    // printForward
    void printForward() const;

    // printBackwards
    void printBackwards() const;

    // insertFront
    void insertFront(int newData);

    void pushTop(int newData); // stack test
    void popTop();             // stack test;
    // insertBack
    void insertBack(int newData);

    // search
    bool search(int key) const;

    // deleteNode
    void deleteNode(int deleteData);

    // sum
    int sum() const;

    // front
    int front() const;

    // back
    int back() const;

    // copyToList
    void copyToList(DoublyList &otherList) const;

    // moveKeyNodeToFirst
    void moveKeyNodeToFirst(int key);

    // destroyList
    void destroyList();

    // destructor
    ~DoublyList();

private:
    Node *first;    // pointer to the first node on the list
    Node *last;     // pointer to the last node on the list
    int count;      // number of nodes in the list
};

#endif