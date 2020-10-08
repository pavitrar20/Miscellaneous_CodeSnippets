#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CHAR 1 
#define INTEGER	2 
#define DOUBLE 3

#define MAXSIZE 64 // absolute max of stack 
// data structure stack - generic

 struct stack {
	size_t top;
	size_t maxSize;  // maximum capacity of stack
	void *elements;
	size_t elemSize;
	int dataType;
};


/***********************************Utility Functions *****************************************/

// intialize an empty stack

struct stack* newStack(int type,size_t totalelems) {
	
	
	struct stack* pt = malloc(sizeof(struct stack));
	if (totalelems > MAXSIZE) return NULL;
	
	pt->dataType = type;
	
	// arbitrarily set max size 
	pt->maxSize = MAXSIZE;
	pt->top = totalelems-1;
// decipher sizeof
		switch(type) {
		case CHAR:
		  pt->elemSize = sizeof(char);
		 break;
		 case INTEGER:
		   pt->elemSize = sizeof(int);
		 break;
		  
		 default:
		  
		 break;
		
	}
	
	// initialize top of stack 
	pt->top = -1; 
	
	// now create space for data
	
	pt->elements = malloc(sizeof(pt->elemSize)*totalelems);
	
	return pt;
}


// push an element ont o stack
void push(struct stack* pt,size_t data) {
	// if stack is not already full push
	if (pt->top <= pt->maxSize-1) {
		// calculate point of insertion in stack along with number of bytes to insert
		void* tmp = (char *)pt->elements+(pt->top)*pt->elemSize;
		memcpy(tmp,(void *)data,pt->elemSize);
	}
	pt->top++;
}


// pop an element off stack

void pop(struct stack* pt,void* data) {
// do only if stack is not empty
	if (pt->top > -1) {
		// retrieve data 
		void* source = (char *)pt->elements+(pt->top*pt->elemSize);
		pt->top--; // decrement top of stack
		memcpy(data,source,pt->elemSize);
	//	printf("Data is %d\n",(int *)(data));
	}
}


int main(void)
{
	printf("Hello, World\n");
	
	void* data;
	// create a stack with 5 integer members
	
	struct stack* ptr = newStack(INTEGER,5);
	
	push(ptr,1);
	push(ptr,2);
	push(ptr,3);
	pop(ptr,data);
	int *d = data;
	printf("Data is %d\n",*d);
	return 0;
}
