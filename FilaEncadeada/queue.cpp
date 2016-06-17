//
// Created by Antony Alkmim on 06/03/16.
//

#include "queue.h"

/**
 * Inicializa a fila com o inicio e fim apontando para NULL pois nao existe elemento ainda
 */
Queue::Queue() {
    this->head = this->tail = NULL;
}

/**
 * Informa se a fila esta vazia
 */
bool Queue::isEmpty() {
    //se o inicio da fila esta apotando para null entao ela esta vazia
    return (head == NULL);
}


/**
 * Insere elementos no final da fila
 * Retorna booleano informando se conseguiu inserir elemento
 */
bool Queue::enqueue(int value) {
    Node *node = Node::createNode(value); //cria um novo node para inserir na fila
    if(!node)
        return false; //retorna falso caso nao houve espaco na memoria para criar um novo node


    if(this->head==NULL) {
        this->head = node; //caso a fila estiver vazia, head aponta para o novo node
    }else{
        //se a fila nao estiver vazia, o proximo elemento de tail passa a apontar para o novo node
        this->tail->next = node;
    }

    this->tail = node; //tail aponta para o novo node criado
    return true; //informa que conseguiu inserir elemento com sucesso
}

/**
 * Remove elemento da fila e retorna em *value
 * Retorna booleano informando se conseguiu remover elemento
 */
bool Queue::dequeue(int *value) {
    //se a fila estiver vazia informa que nao conseguiu remover elemento
    if(this->head == NULL)
        return false;

    //armazena o endereco do proximo elemento da fila
    Node *node = this->head->next;
    //remove o node head
    *value = Node::deleteNode(this->head);
    //head passa a apondar para o proximo node da fila
    this->head = node;

    //informa que conseguiu remover elemento com sucesso
    return true;
}

/**
 * imprime elementos da fila
 */
void Queue::print() {
    Queue queueAux;
    int aux; //auxilizar para retirar elementos da fila original e inserir na fila auxiliar

    cout << "[";
    while(!this->isEmpty()){
        this->dequeue(&aux); //retirar um elemento e armazenar em aux
        queueAux.enqueue(aux); //inserir o elemento na fila auxiliar

        cout << aux << " ";
    }
    cout << "]" << endl;

    //volta os itens da fila auxiliar para a fila original
    while(!queueAux.isEmpty()){
        queueAux.dequeue(&aux);
        this->enqueue(aux);
    }
}

void Queue::init() {
    cout << "Fila inicializada!" << endl;
}
