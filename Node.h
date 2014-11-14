/*******************************************
 * Node.h
 * Author: Antony Alkmim
 ********************************************/

#include <iostream>

using namespace std;

#ifndef NODE_H
#define NODE_H

template <class DataType> class Node
{
	public:
		DataType A; //Data in Node
		Node<DataType> *next; //Next Node reference
		
	public:
		/*
		 * static Node<DataType> *createNode(DataType X)
		 * DataType X: Data to insert in a Node
		 * Create a Node, set the data and return a reference to the Node
		*/
		static Node<DataType> *createNode(DataType X)
		{
			Node<DataType> *p;
			p = new Node;
			if(!p) return p;
			p->A = X;
			p->next = 0;
			
			return p;
		}
		
		/*
		 * static DataType deleteNode(Node<DataType> *P)
		 * Node<DataType> *P: Reference to Node that will delete
		 * Remove Node from memory and return the data
		*/
		static DataType deleteNode(Node<DataType> *P)
		{
			DataType x = P->A;
			delete P;
			return x;
		}
};
#endif
