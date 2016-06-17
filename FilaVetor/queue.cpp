//
// Created by Antony Alkmim on 24/02/16.
//

#include "queue.h"
#include <iostream>

using namespace std;

/**
 * Inicializa fila
 */
Queue::Queue() {
    this->tail = -1; //Inicia com a fila vazia
}

/**
 * Metodo para inicializar a fila
 */
void Queue::init() {
    cout << "Fila Iniciada" << endl;
}

/**
 * Metodo para verificar se a fila esta vazia
 */
bool Queue::isEmpty() {
    return this->tail < 0; //se tail nao possui nenhum indice valido(0-100) entao esta vazia
}

/**
 * Imprime elementos da Fila
 */
void Queue::print() {
    Queue filaAux; //fila auxilizar para armazenar elementos temporariamente
    int aux;

    cout << "[";
    //Retira cada elemento da fila para ser impresso
    while(!this->isEmpty()){
        aux = this->dequeue();
        filaAux.enqueue(aux); //armazena temporariamente na fila auxiliar

        cout << aux << " ";
    }
    cout << "]" << endl;

    /* Retorna elementos da fila temporaria para fila original */
    while(!filaAux.isEmpty()){
        this->enqueue(filaAux.dequeue());
    }
}

/**
 * Adiciona item na fila
 */
void Queue::enqueue(int item) {
    //verifica se fila possui espaco para inserir novo elemento
    if(this->tail == 99)
        return;

    /* Insere o novo item no final da fila */
    this->items[++this->tail] = item;
}

/**
 * Remove e retorna o primeiro item da Fila e move todos os outros itens em uma casa para frente
 * Fila diminui uma casa
 */
int Queue::dequeue() {
    //sempre que a fila estiver vazia retornada -1
    if(this->isEmpty())
        return -1;

    int it = this->items[0]; //armazena o primeiro item da fila para ser retornado

    //move cada item da fila para uma posicao a sua frente
    for(int i=0; i <= this->tail; i++){
        this->items[i] = this->items[i+1];
    }

    this->tail--;
    return it; //retorna o item removido
}


