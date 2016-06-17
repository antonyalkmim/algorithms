#ifndef STACK_H
#define STACK_H


#include <iostream>
#include <string>
#include "node.h"

using namespace std;

class Stack {

public:
    Node *top; //topo da pilha

    Stack(); //inicializa variaveis da pilha
    void init(); //inicializa pilha
    bool push(int value); //Insere elementos na pilha
    bool pop(int *value); //remove elementos da pilha
    bool isEmpty(); //verifica se pilha esta vazia
    void print(); //imprime elementos da pilha
};
;

#endif // STACK_H
