/*******************************************
 * Queue.h
 * Author: Antony Alkmim
 ********************************************/

#include <iostream>
#include "Node.h"

using namespace std;

#ifndef QUEUE_H
#define QUEUE_H

template <class DataType> class Queue
{
	public:
		Node<DataType> *head, *tail;
		
	public:
		Queue()
		{
			this->head = this->tail = NULL; //init queue with head and tail equals NULL (Empty Queue)
		}
		

		/*
		 * bool enqueue(DataType A)
		 * DataType A: Data to insert in a Queue
		 * Insert data into a Queue tail
		*/
		bool Enqueue(DataType A)
		{
			Node<DataType> *P = Node<DataType>::createNode(A); //create a new node to insert in the queue
			if(!P)
				return false;//return false case haven't memory
			
			
			if(this->head==NULL)
			{	
				this->head = P; //case Queue is empty, head now is reference to P
			}else{
				//If queue is not empty, the next node from tail is now a reference to P
				this->tail->next = P; 
			}
			
			this->tail = P; //Tails is a reference to last Node, in the case it is P
			return true; //return true if node insert was successfull
		}
		
		/*
		 * bool dequeue(DataType *A)
		 * DataType* A: Param to return data by reference
		 * Remove the head(first) Node in Queue and return data by param *A.
		 * Returns true if Queue is not empty else false
		*/
		bool Dequeue(DataType *A)
		{
			if(this->head == NULL)
				return false; //case queue is empty
			
			Node<DataType> *P = this->head->next; 
			*A = Node<DataType>::deleteNode(this->head); 
			this->head = P;
			
			return true;
		}

		/*
		 * int size()
		 * Returns the number os elements in the queue
		*/
		int size()
		{
			int i=0;

			if(this->head == NULL)
				return 0; //case queue is empty
			
			Node<DataType> *P = this->head; 
			while(P){
				P = P->next;
				i++;
			}
			
			return i;
		}

};
#endif

	
	
	
	