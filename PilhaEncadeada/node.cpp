//
// Created by Antony Alkmim on 05/03/16.
//

#include <iostream>
#include "node.h"

/**
 * Cria um novo node e retorna o endereco de memoria dele
 */
Node *Node::createNode(int value) {

    //cria um ponteiro para node
    Node *p;
    p = new Node;

    //caso nao conseguir criar um novo node retorna null
    if(!p){
        return p;
    }

    p->value = value; //armazena o valor do elemento
    p->next = NULL; //novo node nao possui proximo node

    return p; //retorna o novo node criado
}


/**
 * Deleta e retorna o valor do elemento armazenado no node passado por parametro
 */
int Node::deleteNode(Node *node) {
    int val = node->value; //armazena o valor do elemento do node
    delete node; //remove o node da memoria
    return val; //retorna o valor que estava armazenado
}
