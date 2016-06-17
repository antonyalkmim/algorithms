#ifndef LIST_H
#define LIST_H

#include "node.h"
#include <iostream>

using namespace std;

class List {

public:
    Node *head; //aponta para primeiro elemento da lista
    Node *tail; //aponta para o final da lista
public:
    List();
    bool insert(int value);
    bool remove(int value, int *x);
    bool isEmpty();
    void print();
};

#endif // LIST_H
