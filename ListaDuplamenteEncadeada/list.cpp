//
// Created by Antony Alkmim on 18/03/16.
//

#include "list.h"

/**
 * Inicializa lista
 */
List::List() {
    this->head = this->tail = NULL;
}

/**
 * Verifica se a lista esta vazia
 */
bool List::isEmpty() {
    return (head==NULL);
}

/**
 * Imprime todos os elementos da lista do primeiro ao ultimo
 */
void List::print() {

    Node *iterator = head;

    if(this->isEmpty()){
        cout << "[ ]" << endl;
        return;
    }

    //imprime todos os elementos do primeiro ao ultimo node
    cout << "[";
    while(iterator){
        cout << iterator->value << " ";
        iterator = iterator->next;
    }
    cout << "]" << endl;

}

/**
 * Insere elementos na lista
 * int pos : indica posicao de insercao. inicio/fim
 */
bool List::insert(int value, int pos) {

    Node *elem = Node::createNode(value);

    //verifica se conseguiu alocar novo node na memoria
    if(!elem) return false;

    //se lista estiver vazia
    if(this->isEmpty()){
        //insere novo elemento no head
        this->head = this->tail = elem;

        //informa que inseriu com sucesso
        return true;
    }

    if(pos == List::INIT){ //INSERE NO INICIO
        elem->next = this->head;
        this->head->prev = elem;
        this->head = elem;
    }else if(pos == List::FINAL){ //INSERE NO FINAL
        this->tail->next = elem; //o proximo do atual tail passa a ser o novo elemento
        elem->prev = this->tail; //node anterior ao novo criado e o antigo tail
        this->tail = elem; //tail passa a apontar para novo elemento
    }


    //informa que inseriu com sucesso
    return true;
}

/**
 * Removera o node que conter value e retornada em (int *x)
 */
bool List::remove(int value, int *x) {

    Node *iterator = this->head;

    if(this->isEmpty()){
        return false;
    }

    // Passar por todos elementos da lista
    while(iterator){

        if(iterator->value == value){ // Encontrou o valor procurado

            if(iterator == this->head){ // Caso for o primeiro da lista
                if(iterator == this->tail){
                    this->head = this->tail = NULL;
                }else{
                    this->head = this->head->next;
                    this->head->prev = NULL;
                }
            }else if(iterator == this->tail){ // Caso for o ultimo
                this->tail = this->tail->prev;
                this->tail->next = NULL;
            }else{ // Caso estiver no meio da lista
                iterator->prev->next = iterator->next;
                iterator->next->prev = iterator->prev;
            }

            *x = Node::deleteNode(iterator);
            return true;
        }

        //passa para o proximo elemento da lista
        iterator = iterator->next;
    }

    // Nao encontrou o valor procurado
    return false;
}

/**
 * Busca value na lista e retorna a posicao do elemento
 */
bool List::search(int value, int *pos) {

    Node *iterator = this->head;
    int i = 0;

    if(this->isEmpty()){
        return false;
    }

    //busca sequencial
    while(iterator){
        if(iterator->value == value){
            *pos = i; //retorna a posicao
            return true; //informa que encontrou o valor procurado
        }
        i++;
        iterator = iterator->next;
    }

    //informa que nao encontrou o elemento
    return false;
}
