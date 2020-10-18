#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define CHAR 1 
#define INTEGER  2 
#define DOUBLE 3

#define MAXSIZE 64 // absolute maximum size of the queue

/***** A generic Queue Implementation 
A queue is a FIFO structure. two pointers keep track of the first element and the last element inserted in the queue

The basic operations are enqueue and dequeue

The last position here wraps back into forst position creating a circular queue

Basic enqueue and dequeue operate as bytes.
So we use this concept to move any kind of data such as integer or double or char

**********************/


 struct queue {
  size_t top;
  size_t rear;
  size_t maxSize;  // requested capacity of queue 
  void *elements;  // data buffer for elements of some typr
  size_t elemSize;
  int dataType;
};

/***********************************Utility Functions *****************************************/

// Create and initialize and empty queue.
// of a certain data type type of a certain size specified by totalelems

struct queue* createQueue(int type,size_t totalelems) {
  
  struct queue* pt =  malloc(sizeof(struct queue));
  
  // if requested size greater than what we arbitrarily set as max size return
  if (totalelems > MAXSIZE) return NULL;
  
  pt->dataType = type;
  pt->top = -1;
  pt->rear = -1;
  
  pt->maxSize = totalelems; // we set the limit of size of queue
  
  // now decipher data type and sizeof data element
  
    switch(type) {
    case CHAR:
      pt->elemSize = sizeof(char);
     break;
     case INTEGER:
       pt->elemSize = sizeof(int);
     break;
      case DOUBLE:
        pt->elemSize = sizeof(double);
      break;
        
     default:
      pt->elemSize = sizeof(char);
     break;
    }  
       
  // now create space for data
  
  pt->elements = malloc(sizeof(pt->elemSize)*totalelems);
  
        return pt;
}
  

// Enqueue an elment
// check if queue us already full 
// if queue is full we have top = 0 and rear = totalelems-1 OR rear = top-1
// return 1 on success and zero on failure
int enqueue(struct queue* pt,size_t data) {
  // queue is full then return
  if ((pt->top == 0) && (pt->rear == pt->maxSize-1) || (pt->rear == (pt->top-1)%(pt->maxSize-1)) )
    return 0;
  
   // if inserting first element
  
  if (pt->top == -1) 
  {
    pt->top = 0;
    pt->rear= 0;
  }
  
  
     if (pt->top > 0 && pt->rear == pt->maxSize-1) // if it is possible wrap to first loc
      pt->rear = 0;
 
  // calculate point of insertion in queue along with number of bytes to insert
    char* tmp = (char *)pt->elements+(pt->rear)*pt->elemSize;
   
  char* source = (char *)&data;
  
    memcpy(tmp,source,pt->elemSize);
 
    pt->rear++;
    
      
  return 1;
}



// dequeue an element, data is the container to hold popped data
// check if queue is empty --> if so return
// if queue is empty top = -1,
// return 1 on success and zero on failure
int dequeue(struct queue* pt,void* data) {
  
  if (pt->top == -1)
     return 0;
  
  // retrieve data 
    void* source = (char *)pt->elements+(pt->top*pt->elemSize);
    pt->top--; // decrement  the top of queue
    memcpy(data,source,pt->elemSize);
  
 //  
  return 1;
}
// Driver 
  
  
  int main(void) {
    
    printf("Hello World\n");
    
    void* data;
    
    // create a queue with 5 elements
    
    struct queue* ptr = createQueue(INTEGER,5);
    
    
   enqueue(ptr,1);
    enqueue(ptr,2);
    enqueue(ptr,3);
    dequeue(ptr,data);
    int* d = data;
    printf("Data is %d\n",*d);
    
   return 0; 
  }