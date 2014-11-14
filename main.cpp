/*******************************************
 * Main.cpp
 * Author: Antony Alkmim
 *
 * Data Structures Examples
 ********************************************/

#include "Stack.h"
#include "Queue.h"


class Dado{
	public:
		int id;
};

int main()
{
	
	Queue<Dado> myqueue;
	Dado a,b,c;
	
	a.id = 1;
	b.id = 3;
	c.id = 5;
	
	myqueue.Enqueue(a); 
	myqueue.Enqueue(b); 
	myqueue.Enqueue(c); 
	
	printf("%i\n",myqueue.size());  //3

	myqueue.Dequeue(&c); 
	printf("%i\n",myqueue.size());  //2
	
	myqueue.Dequeue(&c); 
	printf("%i\n",myqueue.size());  //1
	
	myqueue.Dequeue(&c); 
	printf("%i\n",myqueue.size());  //0
	
	

}