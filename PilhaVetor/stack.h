#ifndef STACK_H
#define STACK_H


#include <string>

class Stack {

private:
    int items[100]; //vetor com elementos da pilha
    int top; //indica qual casa e o top

public:
    Stack(); //inicializa variaveis da pilha
    void init(); //inicializa pilha
    bool isEmpty(); //verifica se pilha esta vazia
    void push(int item); //adiciona item na pilha
    int pop(); //remove elementos da pilha
};


#endif // STACK_H
