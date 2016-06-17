#ifndef NODE_H
#define NODE_H


class Node {

public:
    int value; //valor do elemento
    Node *next; //valor do proximo elemento da cadeia

public:
    //cria um novo node e retorna o endereco de memoria dele
    static Node *createNode(int value);
    //remove e retorna o valor do elemento do node do endereco de memoria informado
    static int deleteNode(Node *node);
};

#endif // NODE_H
