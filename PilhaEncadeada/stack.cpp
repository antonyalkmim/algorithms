//
// Created by Antony Alkmim on 05/03/16.
//

#include "stack.h"

Stack::Stack(){
    this->top = NULL; //inicializa a pilha vazia
}

/**
 * Insere value elementos na pilha
 */
bool Stack::push(int value) {

    //cria um novo node para value
    Node *p = Node::createNode(value);

    //verifica se conseguiu criar um novo node
    if(!p)
        return p; // informa que nao conseguiu criar elemento com sucesso

    //o topo passa a ser o novo node criado
    p->next = this->top;
    this->top = p;

    //informa que conseguiu adicionar novo elemento com sucesso
    return true;
}

/**
 * Remove o topo da pilha.
 * O valor sera retornado em *value que deve receber o endereço de memoria da variavel que ira receber o valor do elemento topo
 * Retorna um booleano informando se conseguiu executar o pop
 */
bool Stack::pop(int *value) {
    //se a pilha estiver vazia retorna false
    if(!top)
        return false;

    //salva o proximo node da pilha
    Node *p = top->next;
    //remove o topo da lista e retorna o valor referente ao topo
    *value = Node::deleteNode(top);
    //o proximo node agora passa a ser o topo
    top = p;

    //informa que conseguiu remover elemento
    return true;
}

/**
 * Informa se a pilha esta vazia
 */
bool Stack::isEmpty() {
    //se o topo a pilha nao apontar para nenhum node e porque a pilha esta vazia
    return (this->top == NULL);
}

/**
 * Descreve a pilha numa String
 */
void Stack::print() {
    Stack stackAux; //pilha auxiliar para armazenar valores retirados da pilha principal
    int aux;

    cout << "[";
    // Enquanto a pilha nao estiver vazia ira:
    while(!this->isEmpty()){
        this->pop(&aux); //retirar um elemento e armazenar em aux
        stackAux.push(aux); //inserir o elemento na pilha auxiliar

        cout << aux << " ";
    }
    cout << "]" << endl;

    //volta os itens da pilha auxiliar para a pilha original
    while(!stackAux.isEmpty()){
        stackAux.pop(&aux);
        this->push(aux);
    }
}

void Stack::init() {
    cout << "Pilha inicializada" << endl;
}
