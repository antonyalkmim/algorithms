#ifndef QUEUE_H
#define QUEUE_H


#include <iostream>
#include <string>
#include "node.h"

using namespace std;

class Queue {

public:
    Node *head; //Head aponta para o primeiro elemento da fila
    Node *tail; //Tail aponta para o ultimo elemento da fila


public:
    Queue(); //inicializa a fila
    void init(); //inicializa fila
    bool enqueue(int value); //empilha elementos na fila
    bool dequeue(int *value); //desenfileira elementos da fila
    bool isEmpty(); //verifica se fila esta vazia
    void print(); //imprime elementos da fila
};
#endif // QUEUE_H
