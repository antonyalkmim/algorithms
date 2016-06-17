#include <iostream>
#include "stack.h"

/* Definicao das contantes de entrada */
static int const INIT = 1;
static int const ADD = 2;
static int const DEL = 3;
static int const IS_EMPTY = 4;
static int const EXT = 6;

using namespace std;

int main() {

    Stack stack;
    int COMMAND; //Auxiliar que ira capturar os comandos
    int num; //auxiliar para capturar os elementos para add/del

    /*Imprimir Header com os possíveis comandos*/
    cout << "###----------------------- PILHA COM VETOR -----------------------###" << endl;
    cout << "Acoes: " << endl;
    cout << INIT << " - Inicializar" << endl;
    cout << ADD << " - Adicionar Item" << endl;
    cout << DEL << " - Remover item" << endl;
    cout << IS_EMPTY << " - Pilha vazia" << endl;
    cout << EXT << " - Sair" << endl << endl;



    while(true){

        /* Ler qual o comando devera executar */
        cout << "> "; cin >> COMMAND;

        /* Iniciar variavel auxiliar para leitura de dados a ser inseridos */
        num = 0;

        switch (COMMAND){
            case INIT: //Iniciar Pilha
                stack.init();
                break;
            case ADD: //Adicionar elementos
                cout << "Numero: ";
                cin >> num;
                stack.push(num);
                break;
            case DEL: //Deletar elementos
                num = stack.pop();
                cout << "Numero removido: " << num << endl;
            case IS_EMPTY : //PilhaVazia?
                cout << "Pilha vazia? " << (stack.isEmpty() ? "Sim" : "Nao") << endl;
                break;
            case EXT: //Sair
                cout << "Pilha finalizada" << endl;
                return 0; //finalizar o programa
        }
    };


}
