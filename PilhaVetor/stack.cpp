//
// Created by Antony Alkmim on 24/02/16.
//

#include "stack.h"
#include <iostream>
#include <string>

using namespace std;
/**
 * Inicia variaveis da pilha
 */
Stack::Stack() {
    this->top = -1; // indica que a pilha esta vazia
}

/**
 * Metodo para iniciar pilha
 */
void Stack::init() {
    //Informa pilha inicializada
    cout << "Pilha Iniciada";
    this->print();
}

/**
 * Verifica se a pilha esta vazia
 */
bool Stack::isEmpty() {
    /* A pilha esta vazia quando o topo nao aponta para nenhum dos itens de 0 a 100 */
    return this->top < 0;
}

/**
 * Insere item no topo da pilha
 */
void Stack::push(int item) {
    //Se a pilha estiver cheia nao insere novos elementos
    if(this->top == 99)
        return;

    //top passa a apontar para novo elemento da pilha
    this->items[++this->top] = item;
}

/**
 * Remove o elemento do topo da pilha
 */
int Stack::pop() {
    //sempre que a pilha estiver vazia, retornara -1
    if(this->isEmpty())
        return -1;

    //retorna o elemento do topo e top passa a apontar para o elemento de baixo
    return this->items[this->top--];
}
