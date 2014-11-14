/*******************************************
 * Main.cpp
 * Author: Antony Alkmim
 *
 * Data Structures Examples
 ********************************************/

#include "Stack.h"
#include "Queue.h"
#include "List.h"

class Dado{
	public:
		int id;
};

int main()
{
	
	List<Dado> lista;
	Dado a,b,c,d,e;
	
	a.id = 1;
	b.id = 2;
	c.id = 3; 
	d.id = 4;
	
	lista.Insert(a);
	lista.Insert(b);
	lista.Insert(c);
	lista.Insert(d);
	
	lista.Delete(1,&e);

	printf("%i\n", lista.size()); //3
	
	

}