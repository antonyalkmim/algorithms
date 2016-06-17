#ifndef LIST_H
#define LIST_H


#include "node.h"
#include <iostream>


using namespace std;

class List {

public:
    Node *head; //aponta para primeiro elemento da lista
    Node *tail; //aponta para o final da lista
    static const int INIT = 1;
    static const int FINAL = 2;

public:
    List();
    bool insert(int value, int pos);
    bool remove(int value, int *x);
    bool search(int value, int *pos);
    bool isEmpty();
    void print();

};

#endif // LIST_H
