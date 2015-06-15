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



##**AVL Tree Usage**

```
#include "AVL.h"
int main(){
	AVL<DataType> myAVL;
}
```

* `bool Insert(DataType A);` Insert A in and re-balance the tree
* `void Delete(int position, DataType* item);` Delete item and re-balance th tree
* `bool Search(int key, DataType *item, TreeNode<DataType> **Root);` Searchthe node by key and put it in `*item`
* `int Height(TreeNode<DataType> *Root);` Return the tree height
* `TreeNode<DataType> *getRoot();` Returns the Tree Root
* `static TreeNode<DataType> *Min(TreeNode<DataType> *Root);` Return lass key in Tree
* `static TreeNode<DataType> *Max(TreeNode<DataType> *Root);` Return mayor key in Tree
* `static void InOrder(TreeNode<DataType> *Root);` Prints the nodes InOrder format
* `static void PreOrder(TreeNode<DataType> *Root);` Prints the nodes PreOrder format
* `static void PosOrder(TreeNode<DataType> *Root);` Prints the nodes PosOrder format