#include <iostream>
#include "queue.h"

/* Definicao das contantes de entrada */
static int const INIT = 1;
static int const ADD = 2;
static int const DEL = 3;
static int const IS_EMPTY = 4;
static int const PRINT = 5;
static int const EXT = 6;

using namespace std;

int main() {

    Queue fila;
    int COMMAND; //Variavel Auxiliar que ira capturar os comandos
    int num; //auxiliar para capturar os elementos para add/del

    /*Imprimir Header com os possíveis comandos*/
    cout << "###----------------------- FILA ENCADEADA -----------------------###" << endl;
    cout << "Acoes: " << endl;
    cout << INIT << " - Inicializar" << endl;
    cout << ADD << " - Adicionar Item" << endl;
    cout << DEL << " - Remover item" << endl;
    cout << IS_EMPTY << " - Fila vazia?" << endl;
    cout << PRINT << " - Imprimir Fila" << endl;
    cout << EXT << " - Sair" << endl << endl;


    while(true){
        /* Ler qual o comando devera executar */
        cout << "> "; cin >> COMMAND;

        /* Iniciar variavel auxiliar para leitura de dados a ser inseridos ou removido*/
        num = 0;

        switch (COMMAND){
            case INIT: //Iniciar Fila
                fila.init();
                break;
            case ADD: //Adicionar elementos
                cout << "Numero: ";
                cin >> num;
                fila.enqueue(num);
                break;
            case DEL: //Deletar elementos
                 if(fila.dequeue(&num)){
                     cout << "Numero removido: " << num << endl;
                 }else{
                     cout << "Pilha vazia, nao foi possivel remover numero" << endl;
                 }
                break;
            case IS_EMPTY : //FilaVazia?
                cout << "Fila vazia? " << (fila.isEmpty() ? "Sim" : "Nao") << endl;
                break;
            case PRINT: //Imprimir Pilha
                cout << "Itens na Fila: ";
                fila.print();
                break;
            case EXT: //Sair
                cout << "Fila finalizada" << endl;
                return 0; //finalizar o programa
        }
    };

}
