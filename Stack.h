/*******************************************
 * Stack.h
 * Author: Antony Alkmim
 ********************************************/

#include <iostream>
#include "Node.h"

using namespace std;

#ifndef STACK_H
#define STACK_H

template <class DataType> class Stack
{
	public:
		Node<DataType> *top; //Reference to Stack top
	
	public:
		Stack()
		{
			top = NULL; //create a empty Stack
		}
		
		/*
		 * Push() 
		 * DataType A: Data to insert in a stack
		 * Insert data into a Stack top
		*/
		bool push(DataType A)
		{
			Node<DataType> *p = Node<DataType>::createNode(A);
			
			if(!p)
				return p;
			
			p->next = top;
			top=p;
			
			return true;
		}
		
		/*
		 * POP
		 * DataType* A: Data return by reference
		 * Remove and return by reference, a data from Stack top
		*/
		bool pop(DataType *A)
		{
			if(!top)
				return false;
			
			Node<DataType> *p = top->next;
			*A = Node<DataType>::deleteNode(top);
			
			top = p;
			return true;
		}
		

		/*
		 * isEmpty
		 * Returns true if Stack is empty else false
		*/
		bool isEmpty()
		{
			return (top == NULL);
		}

		/*
		 * size
		 * Returns a number of nodes in the Stack
		*/
		int size()
		{
			Node<DataType> *tmp = top;
			int i=0;

			while(tmp != NULL){
				tmp = tmp->next;
				i++;
			}

			return i;
		}
		
};

#endif






