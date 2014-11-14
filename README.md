#Data Structures

##**Stack Usage**

```
#include "Stack.h"
int main(){
	Stack<DataType> mystack;
}
```

* `bool push(DataType A);` Push A element in top stack and return true if success else false
* `bool pop(DataType* A);` Pop top element from stack and return data by A param reference
* `bool isEmpty();` Return true if Stack is empty else false
* `int size();` Return the number elements in the Stack



##**Queue Usage**

```
#include "Queue.h"
int main(){
	Queue<DataType> myqueue;
}
```

* `bool Enqueue(DataType A);` Insert A in a last position Queue 
* `bool Dequeue(DataType* A);` Remove the first data in Queue and return data by param *A. Returns true if Dequeue was successfull else false
* `bool isEmpty();` Return true if Queue is empty else false
* `int size();` Return the number elements in the Queue