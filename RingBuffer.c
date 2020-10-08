#include <stdio.h>
#include <stdint.h>

#define BUFFSIZE 32

typedef struct {
    int buffer[BUFFSIZE];
    int head;  // read index
    int Indx;   // index that traverses the buffer
    int tail; // write index 
}circ_buff;


int main() {
	//code
	
 circ_buff cb,* cPtr;
 int pop_data[10];
 
 cPtr=&cb; // point to instantiated object
 
 cPtr->head = cPtr->buffer[0];
 cPtr->tail = cPtr->buffer[0]; 
 // intiailly indices to read and write are same
 // Push data
for (int i=0;i<10;i++) {
    
    cPtr->buffer[i] = i;
    printf("The data at buffer index %d is %d\n",i, cPtr->buffer[i]);
    cPtr->Indx = (cPtr->Indx +1)%BUFFSIZE;
    if (cPtr->Indx == cPtr->tail) {
        printf("No more space to write new data \n");
        break;
    }
}
	// pop data from  buffer
	// adjust index to read from
	cPtr->Indx = cPtr->tail-1; // one location above the next available location to write
	for (int i=0;i<10;i++) {
    
    pop_data[i] = cb.buffer[i];
    printf("The data at popped index %d is %d\n",i, pop_data[i]);
    cPtr->Indx = (cPtr->Indx - 1)%BUFFSIZE;
    
    if (cPtr->Indx == cPtr->head) {
        printf("No more space to read from \n");
    }
    
}



	return 0;
}