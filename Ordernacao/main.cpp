/**
 * PUC-GO
 * 30/06/2016
 * Antony Nelson Daudt Alkmim
 *
 *
 *  Algoritmos de ordenacao
 */

#include <iostream>
#include <stdlib.h>
#include <time.h>

static int const ADD = 1;
static int const DEL = 2;
static int const GEN_RANDOM = 3;
static int const BUBBLESORT = 4;
static int const QUICKSORT = 5;
static int const MERGESORT = 6;
static int const PRINT = 7;
static int const EXT = 8;

using namespace std;

int vetorLength = 0; //quantidade de items no vetor

/**
 * Recebe o vetor de inteiros e imprime os elementos contidos
 * int *vetor
 */
void printVetor(int *vetor){
    cout << "[";
    for(int i=0; i < vetorLength; i++){
        cout << vetor[i] << " ";
    }
    cout << "]" << endl;
}

/**
 * Algoritmo de ordenacao BUBBLE SORT
 * int *vetor : Vetor a ser ordenado
 * int length : Tamanho do vetor
 */
void bubblesort(int *vetor, int length){
    int aux; //auxiliar para fazer swap

    cout << "Inicio: ";
    printVetor(vetor);

    for(int i=length-1, k=0; i >= 1; i--) {
        for(int j=0; j < i ; j++) {
            if(vetor[j] > vetor[j+1]) {
                aux = vetor[j];
                vetor[j] = vetor[j+1];
                vetor[j+1] = aux;

                k++;
                cout << "Passo " << k << ": ";
                printVetor(vetor); //imprimir operacao executada
            }
        }
    }

}

/**
 * Algoritmo de ordenacao QUICK SORT
 * int *vetor : Vetor a ser ordenado
 * int left : posicao do primeiro elemento
 * int right : posicao do ultimo elemento
 * int *passo : ponteiro para informar a quantidade de passos que estao sendo executados
 */
void quicksort(int *vetor, int left, int right, int *passo){

    int i = left, j = right;
    int tmp;
    int pivot = vetor[(left + right) / 2];

    /* Partition */
    while (i <= j) {
        while (vetor[i] < pivot)
            i++;
        while (vetor[j] > pivot)
            j--;
        if (i <= j) {
            tmp = vetor[i];
            vetor[i] = vetor[j];
            vetor[j] = tmp;
            i++;
            j--;
        }
    };

    //imprimir operacao executada
    cout << "Passo " << *passo << ": ";
    printVetor(vetor);

    *passo += 1; // flag para informar quantos passos foram executados ate o momento

    /* ordernar recursivamente o lado esquerdo */
    if (left < j)
        quicksort(vetor, left, j, passo);
    /* ordernar recursivamente o lado direito */
    if (i < right)
        quicksort(vetor, i, right, passo);


}


/**
 * Ordena o vetor fazendo os 'merges'
 * int *vetor : Vetor a ser ordenado
 * int init_pos : posicao do primeiro elemento do vetor
 * int end_pos : posicao do ultimo elemento do vetor
 * int *passo : flag pra informar quantos passos foram executados
 */
void mergesort(int *vetor, int init_pos, int end_pos, int *passo){

    int i, j, k, middle, *vetorTemp;

    if(init_pos >= end_pos) return; //se existir apenas 1 elemento nao é necessario ordenar

    // middle indica o meio do vetor para saber quais sao seus respectivos left e right
    middle = (init_pos + end_pos ) / 2;

    //ordena a metade da esquerda
    mergesort(vetor, init_pos, middle, passo);
    //ordernar a metade da direita
    mergesort(vetor, middle + 1, end_pos, passo);

    // intercalacao no vetor temporario t
    i = init_pos;
    j = middle + 1;
    k = 0;
    
    //vetor temporario para alocar os elementos ordenados
    vetorTemp = (int *) malloc(sizeof(int) * (end_pos - init_pos + 1));

    //ordena o vetor temporario atual
    while(i < middle + 1 || j  < end_pos + 1) {
        if (i == middle + 1 ) { // i passou do final da primeira metade, pegar v[j]
            vetorTemp[k] = vetor[j];
            j++;
            k++;
        }
        else {
            if (j == end_pos + 1) { // j passou do final da segunda metade, pegar v[i]
                vetorTemp[k] = vetor[i];
                i++;
                k++;
            }
            else {
                if (vetor[i] < vetor[j]) {
                    vetorTemp[k] = vetor[i];
                    i++;
                    k++;
                }
                else {
                    vetorTemp[k] = vetor[j];
                    j++;
                    k++;
                }
            }
        }

    }

    // copia vetor intercalado para o vetor original
    for(i = init_pos; i <= end_pos; i++) {
        vetor[i] = vetorTemp[i - init_pos];
    }
    free(vetorTemp); //remove vetor temporario da memoria

    //informa as alteracoes que foram feitas no vetor
    *passo += 1;
    cout << "Passo " << *passo << ": ";
    printVetor(vetor);

    return;
}


int main() {

    int *vetor = new int; //ponteiro para vetor dinamico
    int COMMAND;
    int num; //auxiliar para ler os numeros informados pelo usuario
    int passo; //auxiliar para informar quantos passos foram executados

    //gerar numeros aleatorios 
    srand (time(NULL));

    /*Imprimir Header com os possíveis comandos*/
    cout << "###----------------------- ORDENAÇÃO -----------------------###" << endl;
    cout << "Acoes: " << endl;
    cout << ADD << " - Adicionar Item" << endl;
    cout << DEL << " - Remover item" << endl;
    cout << GEN_RANDOM << " - Gerar vetor aleatório" << endl;
    cout << BUBBLESORT << " - Bubblesort" << endl;
    cout << QUICKSORT << " - Quicksort" << endl;
    cout << MERGESORT << " - Mergesort" << endl;
    cout << PRINT << " - Print" << endl;
    cout << EXT << " - Sair" << endl << endl;


    while (true){

        /* Ler qual o comando devera executar */
        cout << "> "; cin >> COMMAND;

        /* Iniciar variavel auxiliar para leitura de dados a ser inseridos ou removido*/
        num = 0;

        switch (COMMAND){
            case ADD: //Adicionar elementos
                cout << "Numero: ";
                cin >> num;

                vetor[vetorLength] = num;
                vetorLength++;
                break;
            case DEL: //Deletar elementos
                bool finded;
                int j;

                cout << "Numero: ";
                cin >> num;

                finded = false; //flag para informar se achou elemento no vetor
                j=0;

                //buscar numero a ser removido
                while(!finded && j < vetorLength){
                    if(vetor[j] == num){
                        finded = true;
                    }
                    j++;
                }

                /*
                   Caso remover algum elemento, 
                   deve-se voltar todos os seguintes elementos para uma casa anterior
                 */ 
                while(j < vetorLength){
                    vetor[j-1] = vetor[j];
                    j++;
                }

                //caso removeu elemento, entao o tamanho do vetor é subtraido 1
                if(finded){
                    vetorLength--;
                }else{
                    //nao encontrou elemento para ser removido
                    cout << "Numero informado não foi encontrado!" << endl;
                }

                //imprimir os elementos contidos no vetor
                cout << "Vetor: [";
                for(j=0; j < vetorLength; j++)
                    cout << vetor[j] << " ";
                cout << "]" << endl;

                break;
            case GEN_RANDOM : //GERAR vetor aleatorio
                cout << "Quantidade de numero: ";
                cin >> num;

                vetorLength = num;

                //gera e imprime o vetor gerado aleatoriamente
                cout << "Vetor gerado: [";
                for(int i=0; i < num; i++){
                    vetor[i] = rand() % 100; //gera numero aleatorio entre 0 e 100

                    cout << vetor[i] << " ";
                }
                cout << "]" << endl;

                break;
            case PRINT: //Imprimir Vetor
                printVetor(vetor);
                break;
            case BUBBLESORT : //ordernar vetor com Bubblesort
                bubblesort(vetor, vetorLength);

                //imprimir vetor apos ordenacao
                cout << "Vetor Ordenado: ";
                printVetor(vetor);
                break;
            case QUICKSORT : //ordernar vetor com Quicksort
                cout << "Inicio: ";
                printVetor(vetor);

                passo = 0;
                quicksort(vetor, 0, vetorLength-1, &passo);

                //imprimir vetor apos ordenacao
                cout << "Vetor Ordenado: ";
                printVetor(vetor);
                break;
            case MERGESORT : //ordernar vetor com Mergesort
                cout << "Inicio: ";
                printVetor(vetor);

                passo = 0;
                mergesort(vetor, 0, vetorLength-1, &passo);

                //imprimir vetor apos ordenacao
                cout << "Vetor Ordenado: ";
                printVetor(vetor);
                break;
            case EXT: //Sair
                cout << "Finalizando Programa!" << endl;
                return 0; //finalizar o programa
        }


    }


}