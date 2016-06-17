#ifndef QUEUE_H
#define QUEUE_H


#include <string>

class Queue {
private:
    int items[100]; //vetor com itens da fila
    int tail; //marca o final da fila
public:
    Queue(); //inicializa variaveis da fila
    void init(); //inicializa fila
    void enqueue(int item); //enfileira items
    int dequeue(); //desenfileira items
    bool isEmpty(); //verifica se fila esta vazia
    void print(); //imprime items da fila
};

#endif // QUEUE_H
