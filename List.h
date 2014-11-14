/*******************************************
 * List.h
 * Author: Antony Alkmim
 ********************************************/

#include <iostream>

using namespace std;

#ifndef LIST_H
#define LIST_H

template <class DataType> class List
{
	private:
		Node<DataType> *head;
	
	public:
		List(){
			this->head = NULL;
		}
		
		bool Insert(DataType X){
			Node<DataType> *P = Node<DataType>::createNode(X);
			if(!P)
				return false;
			
			P->next = this->head;
			this->head = P;
			return true;
		}
		
		bool Delete(int key, DataType *X){
			Node<DataType> **P = &this->head;
			Node<DataType> *Q;
			
			while((*P) && (*P)->A.id!=key){
				P = &(*P)->next;
			}
			
			if(!(*P))
				return false;
			
			Q = (*P);
			(*P) = (*P)->next;
			*X = Node<DataType>::deleteNode(Q);
			return true;
		}


		/*
		 * int size()
		 * Returns the number os elements in the list
		*/
		int size()
		{
			int i=0;
			Node<DataType> *P = this->head; 
			while(P){
				P = P->next;
				i++;
			}
			return i;
		}
};

#endif //LIST_H







