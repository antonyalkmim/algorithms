#include <iostream>
#include "list.h"

/* Definicao das contantes de entrada */
static int const ADD = 1;
static int const DEL = 2;
static int const IS_EMPTY = 3;
static int const PRINT = 4;
static int const TAIL_NEXT = 5;
static int const EXT = 6;

using namespace std;

int main() {

    List lista;
    int COMMAND; //Variavel Auxiliar que ira capturar os comandos
    int num; //auxiliar para capturar os elementos para add/del

    /*Imprimir Header com os possíveis comandos*/
    cout << "###----------------------- LISTA CIRCULAR -----------------------###" << endl;
    cout << "Acoes: " << endl;
    cout << ADD << " - Adicionar Item" << endl;
    cout << DEL << " - Remover item" << endl;
    cout << IS_EMPTY << " - Lista vazia?" << endl;
    cout << PRINT << " - Imprimir Fila" << endl;
    cout << TAIL_NEXT << " - Proximo do ultimo" << endl;
    cout << EXT << " - Sair" << endl << endl;


    while(true){
        /* Ler qual o comando devera executar */
        cout << "> "; cin >> COMMAND;

        /* Iniciar variavel auxiliar para leitura de dados a ser inseridos ou removido*/
        num = 0;

        switch (COMMAND){
            case ADD: //Adicionar elementos
                cout << "Numero: ";
                cin >> num;
                lista.insert(num);
                break;
            case DEL: //Deletar elementos
                int aux;
                cout << "Numero: ";
                cin >> num;
                if(lista.remove(num, &aux)){
                    cout << "Numero removido: " << aux << endl;
                }else{
                    cout << "Numero nao foi encontrado!" << endl;
                }
                break;
            case IS_EMPTY : //ListaVazia?
                cout << "Lista vazia? " << (lista.isEmpty() ? "Sim" : "Nao") << endl;
                break;
            case PRINT: //Imprimir Lista
                cout << "Itens na Lista: ";
                lista.print();
                break;
            case TAIL_NEXT :
                if(!lista.isEmpty()){
                    cout << "Proximo elemento do ultimo: " << lista.tail->next->value << endl;
                }else{
                    cout << "Lista vazia!" << endl;
                }
                break;
            case EXT: //Sair
                cout << "Lista finalizada" << endl;
                return 0; //finalizar o programa
        }
    };

}
