#include "TreeNode.h"
#include <iostream>

using namespace std;

#ifndef AVL_H
#define AVL_H

template<class myType>
class AVL{
    public:
        TreeNode<myType> *Root;

    public:
        AVL(){
            Root = NULL;
        }

        /*
         * Retorna um apontador para a raiz da arvore
         */
        TreeNode<myType> *getRoot(){
            return Root;
        }

        /*
         * Metodo para insercao de Nodes na arvore
         * => Chama o Metodo Insert que insere recursivamente na arvore
         * Dado x => Dado para ser inserido na arvore
         */
        bool Insert(myType x){
           return this->Insert(x,&this->Root);
        }

        /*
         * Metodo para remover de Nodes na arvore
         * => Chama o Metodo DeleteAVL que insere recursivamente na arvore
         * Dado x => Dado encontrado e retornado por ponteiro
         * Retorna boolean indicando se item foi encontrado
         */
        bool Delete(int pos, myType *x){
            return DeleteAVL(pos, x, &Root);
        }

        /*
         *AVL::Search(int key, Dado *x, TreeNode **Raiz);
         *Busca um node com chave key na arvore com raiz (*Raiz)
         *e armazena em x
         */
        bool Search(int key, myType *x, TreeNode<myType> **Raiz){

            if(!(*Raiz))
                return false;

            if(key < (*Raiz)->A.id)
                return Search(key, x, &(*Raiz)->Left);
            if(key > (*Raiz)->A.id)
                return Search(key, x, &(*Raiz)->Right);


            //se chegar aqui e pq achou a chave que procura
            *x = (*Raiz)->A;
            return true;
        }

        /*
         *AVL::Height(TreeNode *Raiz);
         *TreeNode *Raiz : Nó raiz na qual comeca a contagem da altura da arvore
         */
        int Height(TreeNode<myType> *Raiz){

             int altE, altD;

             TreeNode<myType> *q, *temp;
             if (!(Raiz))
                 return 0;
             else
             {
                 altE = Height((Raiz)->Left);
                 altD = Height((Raiz)->Right);

                 if (altE < altD)
                    return altD + 1;
                 else
                    return altE + 1;
             }

        }

        /*
         *AVL::Min(TreeNode *Raiz);
         *TreeNode *Raiz : Informa o TreeNode Raiz de uma arvore
         *Busca o TreeNode com a menor chave na arvore de Raiz = *Raiz
         */
        static TreeNode<myType> *Min(TreeNode<myType> *Raiz){

            if(!Raiz->Left){
                return Raiz;
            }

            return Min(Raiz->Left);

        }

         /*
         *AVL::Max(TreeNode *Raiz);
         *TreeNode *Raiz : Informa o TreeNode Raiz de uma arvore
         *Busca o TreeNode com a maior chave na arvore de Raiz = *Raiz
         */
        static TreeNode<myType> *Max(TreeNode<myType> *Raiz){

            if(!Raiz->Right){
                return Raiz;
            }

            return Max(Raiz->Right);

        }

        /*
         *AVL::InOrder(TreeNode *Raiz);
         *(*Raiz) : No raiz de uma arvore para poder percorrer
         *Percorre a Arvore in-order
         */
        static void InOrder(TreeNode<myType> *Raiz){
            if(Raiz){
                InOrder(Raiz->Left);
                cout << Raiz->A.getX() << " ";
                InOrder(Raiz->Right);
            }
        }

        /*
         *AVL::PreOrder(TreeNode *Raiz);
         *(*Raiz) : No raiz de uma arvore para poder percorrer
         *Percorre a Arvore pre-order
         */
        static void PreOrder(TreeNode<myType> *Raiz){
            if(Raiz){
                cout << Raiz->A.id << " ";
                PreOrder(Raiz->Left);
                PreOrder(Raiz->Right);
            }
        }

        /*
         *AVL::PosOrder(TreeNode *Raiz);
         *(*Raiz) : No raiz de uma arvore para poder percorrer
         *Percorre a Arvore pos-order
         */
        static void PosOrder(TreeNode<myType> *Raiz){
            if(Raiz){
                PosOrder(Raiz->Left);
                PosOrder(Raiz->Right);
                cout << Raiz->A.id << " ";
            }
        }

        /**
        * Limpa todos os filhos de Raiz
        */
        static void Clear(TreeNode<myType> *Raiz){
            if(Raiz)
                iclear(&Raiz);
        }

        /**
        * Remove todos os Nodes da arvore
        */
        void Clear(){
            if(this->Root)
                iclear(&this->Root);
        }

    protected:
        /**
        * Remove all the childrens from Root
        */
        void iclear(TreeNode<myType> **Raiz){

            if((*Raiz)){
                TreeNode<myType> *P;

                iclear(&(*Raiz)->Left);
                iclear(&(*Raiz)->Right);

                P = *Raiz;
                *Raiz = NULL;
                TreeNode<myType>::desmontaNo(P);
            }
        }


        /*
         *AVL::Insert(Dado x, TreeNode **Raiz);
         *Dado x : Objeto do tipo dado que armazenaremos na arvore
         *TreeNode **Raiz : Ponteiro que aponta para o Ponteiro Raiz da Arvore ou sub-arvore
         *Metodo para inserir um Dado na Arvore Binaria
         */
        bool Insert(myType x, TreeNode<myType> **Raiz){

            if(!(*Raiz)){
                (*Raiz) = TreeNode<myType>::montaNo(x);

                if(!(*Raiz))
                    return false;
                return true;
            }

            //verifica se a chave do dado e menor que a chave do TreeNode Raiz
            if(x.id < (*Raiz)->A.id){
                 if(Insert(x, &(*Raiz)->Left)){

                     if((*Raiz)->FB == 1){
                        (*Raiz)->FB = 0;
                         return false;
                     }

                     if((*Raiz)->FB == 0){
                         (*Raiz)->FB = -1;
                         return true;
                     }


                     if((*Raiz)->Left->FB != 1){
                         RSD(Raiz);
                     }else{
                         RDD(Raiz);
                     }

                     return false;
                }
                return false;
            }

            if(x.id > (*Raiz)->A.id){
                 if(Insert(x, &(*Raiz)->Right)){

                     if((*Raiz)->FB == -1){
                        (*Raiz)->FB = 0;
                         return false;
                     }

                     if((*Raiz)->FB == 0){
                         (*Raiz)->FB = 1;
                         return true;
                     }


                     if((*Raiz)->Right->FB != -1){
                         RSE(Raiz);
                     }else{
                         RDE(Raiz);
                     }

                     return false;
                }
                return false;
            }


            return false; //deu erro na insercao
        }



        bool DeleteAVL(int key, myType *x, TreeNode<myType> **Raiz){
            if(!(*Raiz))
                return false; //chave nao encontrada

            if(key < (*Raiz)->A.id){

                if(DeleteAVL(key, x, &(*Raiz)->Left)){

                    if((*Raiz)->FB == -1){
                        (*Raiz)->FB = 0;
                        return true;
                    }
                    if((*Raiz)->FB == 0){
                        (*Raiz)->FB = 1;
                        return false;
                    }

                    //so pode ser +1
                    if((*Raiz)->Right->FB != 1){
                        RDE(Raiz);
                        (*Raiz)->FB = 0;
                    }else{
                        RSE(Raiz);
                    }
                    return true;
                }
                return false;
            }
            if(key > (*Raiz)->A.id){
                if(DeleteAVL(key, x, &(*Raiz)->Right)){

                    if((*Raiz)->FB == 1){
                        (*Raiz)->FB = 0;
                        return true;
                    }

                    if((*Raiz)->FB == 0){
                        (*Raiz)->FB = -1;
                        return false;
                    }

                    //so pode ser -1
                    if((*Raiz)->Left->FB != -1){
                        RDD(Raiz);
                    }else{
                        RSD(Raiz);
                    }
                    return true;

                }
                return false;
            }

            TreeNode<myType> *P = *Raiz;
            if(!(*Raiz)->Left){ //nao tem filho a esquerda
                *Raiz = (*Raiz)->Right;
                *x = TreeNode<myType>::desmontaNo(P);
                return true;
            }

            if(!(*Raiz)->Right){ //tem filho somente a esquerda
                *Raiz = (*Raiz)->Left;
                *x = TreeNode<myType>::desmontaNo(P);
                return true;
            }

            //tem 2 filhos
            TreeNode<myType> *m = AVL<myType>::Max((*Raiz)->Left);
            myType aux = m->A;
            m->A = (*Raiz)->A;
            (*Raiz)->A = aux;



            if(DeleteAVL(key,x,&(*Raiz)->Left)){
                if((*Raiz)->FB == -1){
                    (*Raiz)->FB = 0;
                    return true;
                }
                if((*Raiz)->FB == 0){
                    (*Raiz)->FB = 1;
                    return false;
                }
                //so pode ser +1
                if((*Raiz)->Right->FB != 1){
                    RDE(Raiz);
                }else{
                    RSE(Raiz);
                }
                return true;
            }


        }


        /*
         *R.D.D. : ROTACAO DUPLA PARA DIREITA
         *AVL::RDD(TreeNode **Raiz);
         *TreeNode **Raiz: TreeNode para se aplicar a Rotacao
         *Efetua a rotacao dupla para Direita em um determinado TreeNode **Raiz
         */
        void RDD(TreeNode<myType> **Raiz){
            TreeNode<myType> *b,*c;

            b = (*Raiz)->Left;
            c = b->Right;

            //rotaciona
            (*Raiz)->Left = c->Right;
            b->Right = c->Left;
            c->Right = (*Raiz);
            c->Left = b;

            //cout << "ROTACAO DUPLA DIREITA" << endl;

            //atualiza o fator de balanceamento
            if(c->FB == 1){
                (*Raiz)->FB = 0;
                b->FB = -1;
            }else{
                if(c->FB == 0){
                    (*Raiz)->FB = 0;
                    b->FB = 0;
                }else{
                    (*Raiz)->FB = 1;
                    b->FB = 0;
                }
            }
            c->FB = 0;
            (*Raiz) = c;

        }

        /*
         *R.D.E. : ROTACAO DUPLA PARA ESQUERDA
         *AVL::RDE(TreeNode **Raiz);
         *TreeNode **Raiz: TreeNode para se aplicar a Rotacao
         *Efetua a rotacao dupla para Esquerda em um determinado TreeNode **Raiz
         */
        void RDE(TreeNode<myType> **Raiz){
            TreeNode<myType> *b,*c;

            b = (*Raiz)->Right;
            c = b->Left;

            //cout << "ROTACAO DUPLA ESQUERDA" << endl;

            //rotaciona
            (*Raiz)->Right = c->Left;
            b->Left = c->Right;
            c->Left = (*Raiz);
            c->Right = b;

            //atualiza o fator de balanceamento
            if(c->FB == 1){
                (*Raiz)->FB = -1;
                b->FB = 0;
            }else{
                if(c->FB == 0){
                    (*Raiz)->FB = 0;
                    b->FB = 0;
                }else{
                    (*Raiz)->FB = 0;
                    b->FB = 1;
                }
            }
            c->FB = 0;
            (*Raiz) = c;
        }

        /*
         *R.S.E. : ROTACAO SIMPLES PARA ESQUERDA
         *AVL::RSE(TreeNode **Raiz);
         *TreeNode **Raiz: TreeNode para se aplicar a Rotacao
         *Efetua a rotacao simples para esquerda em um determinado TreeNode **Raiz
         */
        void RSE(TreeNode<myType> **Raiz){
            TreeNode<myType> *b = (*Raiz)->Right;
            (*Raiz)->Right = b->Left;
            b->Left = (*Raiz);

            //cout << "Entrou na rotacao pra esquerda" << endl;

            //atualiza fator de balanceamento
            if(b->FB == 1){
                b->FB = 0;
                (*Raiz)->FB = 0;
            }else{
                b->FB = -1;
                (*Raiz)->FB = 1;
            }

            (*Raiz) = b;
        }

        /*
         *R.S.D. : ROTACAO SIMPLES PARA DIREITA
         *AVL::RDD(TreeNode **Raiz);
         *TreeNode **Raiz: TreeNode para se aplicar a Rotacao
         *Efetua a rotacao Simples para Direita em um determinado TreeNode **Raiz
         */
        void RSD(TreeNode<myType> **Raiz){
            TreeNode<myType> *b = (*Raiz)->Left;
            (*Raiz)->Left = b->Right;
            b->Right = (*Raiz);


            //atualiza o fator de balanceamento
            if(b->FB == -1){
                b->FB = 0;
                (*Raiz)->FB = 0;
            }else{
                b->FB = 1;
                (*Raiz)->FB = -1;
            }
            (*Raiz) = b;
        }


};

#endif // AVL_H
