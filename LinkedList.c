#include<stdio.h>
#include<stdlib.h>

struct LinkedList {
    int data;
    struct LinkedList* next;
    
};

/***********************Utility Functions ------*************/
/*
3 step building process - 
1.A temp pointer to present head of list;allocated head
    1a.Initialliy only head node is allocated. Temp points to this and next is NULL
2. Another node is allocated and data is pushe donto it. Now next int he new node is initally NULL
    2A. tmp which is also pointing to head node has its next pointing to the newly allocated nodde
3. Once head has been linked thus to new node, temp itself points to new node to facilitate insertion of next new node
*/
struct LinkedList *BuildSimpleList(struct LinkedList* head,int numOfItems) {
        
         struct LinkedList* newNode;
        struct LinkedList* tmp;
    head = malloc(sizeof( struct LinkedList)); // allocate  nodes in the heap
  
    tmp = head;
    head->data = 0;
    head->next = NULL;
    
    for (int i=1;i<numOfItems;i++) {
        newNode= malloc(sizeof( struct LinkedList)); 
        newNode->data = i;
        newNode->next = NULL; // newly allocated node is tail
        // tmp is now head initially - here we are referring to prev node to new node
        tmp->next=newNode;  // Previous Node's next -->tmp which is first head->next now points to new node
        tmp=tmp->next; // now tmp is the address of new node and becomes current node
          printf("tmp Address is %zx and and data is %d\n",tmp,tmp->data);
    }
    
    
 
// At this point, the linked list referenced by "head"
// matches the list in the drawing.
    printf("Head Address is %zx and cnext node is %zx and data is %d\n",head,head->next,head->data);
return head;
  
}

void printList(struct LinkedList* head) {
    struct LinkedList* temp = head;
 
     while (temp != NULL) {
       printf("Data  is %d\n",temp->data);
        temp = temp->next;
    }
    
}

int count(struct LinkedList* head) {
    int count = 0;
    struct LinkedList* temp = head;
  
    while (temp!= NULL) {
          count++;
        temp = temp->next;
    }

return count;    
}

/*
Given a list and an int, return the number of times that int occurs
in the list.
*/
    
int SearchItem(struct LinkedList* head,int item) {
    
  int count  = 0;
  struct LinkedList* temp = head;
    
    for (temp;temp!=NULL;temp=temp->next) {
        if(temp->data == item)
             return count;
    }
    return count;
}

void deleteList(struct LinkedList* head) {
    struct LinkedList* tmp=head;
    struct LinkedList* tmp1=NULL;
    while (tmp != NULL) {
        tmp1=tmp;
        tmp=tmp->next;
        free(tmp1);
    }
    head = NULL;
}

/*
Push adding the link to the head end
*/

struct LinkedList* push(struct LinkedList* head,int item) {
    // create a new node to push item in
    struct LinkedList* newNode = malloc(sizeof(struct LinkedList));
    newNode->data = item;
    // this will be inserted in front of old head. so next will point to head
    newNode->next= head;
    head=newNode;
    
    return head;
}
/*
Pop() takes a non-empty list, deletes
the head node, and returns the head node's data.
Use reference to head pointer
*/

int pop(struct LinkedList** headref) {
    struct LinkedList* tmp = &headref;
  
    int data=0;
    // Save old head' next which will later serve as new head
    
    tmp= (*headref)->next;
    // unlink head node to point to next node
    (*headref) = tmp;
    
    // return old head node's data and free the node
    data = tmp->data;
    free(tmp);
    
    return data;
}
/*
InsertNth which can insert a new node at any index within a list
Returns nothing. Head Pointer changes only if is a push
that is insertion at head. Here we assume we do not insert at Head.
Parameters: data and index of insertion plus reference to head of Linked List
*/

void InsertNthNode(int index, int data,struct LinkedList** headref) {
 int len = 0;
    struct LinkedList* tmp = *headref; // tmp first points to head
    struct LinkedList* prev = tmp;
    int Indx=0; // current traversal Indx
    while (tmp != NULL) {
        if(Indx == index) {// insert new node if we need to it here at this index
            struct LinkedList *newNode = malloc(sizeof(struct LinkedList));
             newNode->data = data;
            newNode->next=tmp; // new node will now next link to temp
            tmp = newNode; // current pointer now is new Node
            // special case of head
            if (index == 0){ 
          
                (*headref) = tmp; // adjust head if inserting in first place
                break;
            }
            // in all other cases
          
            prev->next = tmp; // previous node will now point to new node
            break; // break after insertion
        }
        else {
        Indx++;
        prev= tmp; // prev points to node that is currnt tmp and will become  previous to tmp
        tmp=tmp->next; // tmp advances to next node
        }
    }
    
}

/***********************************************************************
SortedInsert() given a list that is sorted in increasing order, and a
single node, inserts the node into the correct sorted position in the list
****************************************************************************/
void SortedInsert(struct LinkedList** headRef, struct LinkedList* newNode) {
    struct LinkedList* tmp= *headRef; // keep track of current node
    struct LinkedList* prev=tmp; // keep track of previous node
    // trverse the list and check where to insert the node
    
    // check for first node insertion after head
     if (tmp->next == NULL ) {
        // insert here as there are no nodes
          if (newNode->data >= tmp->data) { // insert after head
              newNode->next = NULL;//last node
              tmp->next = newNode; // link to previous node
              tmp = newNode;
          }
         else { // insert before head and adjust head
              newNode->next = tmp;//new node will point to old head
              tmp=newNode; // curr Node is tmp 
              *headRef = tmp; // new head pointing to new Node
         }
        }
    while(tmp != NULL) {
       if (tmp->next != NULL) { // insertion in the middle
        if (newNode->data >= tmp->data && newNode->data <= (tmp->next)->data) {
            // insert node here
            newNode->next = tmp->next; // new node point to what temp is pointing to
            tmp->next = newNode; // unlink tmp and now link to new node
            break;
        }
       }
       else  { // insert after current last node; tmp is the last node 
           if (newNode->data >= tmp->data) { // insert after tmp
                // insert node here
                newNode->next = tmp->next; // new node point to what temp is pointing to
                tmp->next = newNode; // unlink tmp and now link to new node
            break;   
           }
        /*   else { // insert before temp - this check is redundant for value check-already done in main while loop
              
              break; 
           }*/
       } // end else
      
        tmp=tmp->next;// advance to next node
    }
    
}

/*
Remove duplicates from a sorted list.
*/
void RemoveDuplicates(struct LinkedList* head) {
    // initially all point to head
    struct LinkedList* tmp = head;
    
    
    printf("Head is %zx\n",head);
 
    if (tmp == NULL) return; // do nothing if an empty list
    
    while (tmp->next != NULL) { // if two consecutive nodes have same value
        
        if ((tmp->data) == ((tmp->next)->data)) {
            struct LinkedList* nextPtr = tmp->next->next;
            tmp->next = nextPtr; // unlink the duplicate node. Make current node point to one after the dulicate node - this takes care even if next points to NULL
    
        }
        else{
         
          tmp=tmp->next; // advance tmp to next node only if no duplicate 
         }
         printf("tmp is %zx\n",tmp);
         printf("Next is %zx\n",tmp->next); 
    }
    
    
} 


/****************************************************************************
Reverse a linked List
************************************************************************/
void Reverse(struct LinkedList** headRef) {
    struct LinkedList* tmp = *headRef; // point to head - original
    struct LinkedList* newNext = tmp; // pointer for reverse list
     struct LinkedList* result = NULL;
    
    while(tmp != NULL) {
     newNext = tmp->next;
    tmp->next = result;
        result = tmp;
       
        tmp=newNext;
        
    }
    *headRef = result; // adjust head finally
}

/************************************************************************
MoveNode() - Instead of creating a new node and pushing it onto the given
list, MoveNode() takes two lists, removes the front node from the second list 
and pushes it onto the front of the first. A is destination list
b is source list. Moce will be one node from b to a
*************************************************************************/
void MoveNode(struct LinkedList** aRef, struct LinkedList** bRef) {
    if (*aRef == NULL && *bRef == NULL)
        return;
    else if (*aRef == NULL) {
        *aRef= *bRef;
    }
    else if (*bRef == NULL) {
        return;
    }
    else { // main code of move node
        struct LinkedList* aTmp = *aRef;
        struct LinkedList* bTmp = *bRef;
        
        struct LinkedList* tmp = bTmp;
        //unlink first noe in b list and move its head one down 
        if (tmp->next != NULL) 
                *bRef = tmp->next;
        bTmp->next = aTmp; // unlinked node points to first node in a list
        aTmp= bTmp; // move head one up in a list
        
    }
    
    
        return;
}

/**************************************************************************************
Write an Append() function that takes two lists, 'a' and 'b', appends 'b' onto the end of 'a', and then sets 'b' to NULL
***************************************************************************************/
void append(struct LinkedList** aRef,struct LinkedList** bRef) {
    struct LinkedList* tmp = *aRef;
    
    // Empty a list means just point a to b
    if (*aRef == NULL)
        *aRef = *bRef;
    else
    {
       while(tmp->next != NULL) {
           // keep advancing through a list until we reach end
           tmp=tmp->next;
       }
        // now we are last node of a
    
        // link last node of a with first node of b
        tmp->next = *bRef;  
        
        // destroy reference to b 
        *bRef = NULL;
    }
}

/*******************************************************************************
SortedMerge() function that takes two lists, each of which is sorted in increasing
order, and merges the two together into one list which is in increasing order.
SortedMerge() should return the new list.
The caller must free the list or delete list - this is the contract
*************************************************************************************/
struct LinkedList* SortedMerge(struct LinkedList* a,struct LinkedList* b) {
    
    struct LinkedList* result = NULL ; // a tmp ptr
    struct LinkedList** ptr = result;
    
  while(1)  {
    if (a == NULL ) {
        *ptr= b;
        break;
    }
    else if (b == NULL)  {
        *ptr= a;
        break;
    } 
        
    else { // main body of code
      
   if (a->data <= b->data)
       MoveNode(ptr,&a);
    else
        MoveNode(ptr,&b);
    }
    ptr= &((*ptr)->next);  // advance to next node in result
   } // end while 
     return result;
}

/*****************************MAIN****************************************************/
int main(void) {
    
    struct LinkedList* head=NULL;
    puts("Hello World!");
    
    // create a simple list with three elements
    head = BuildSimpleList(head,3);
 
    
    printList(head);
    
    int elements = count(head);
 printf("Count is %d\n",elements); // 
    int item = 2;
    int numofElem = SearchItem(head,item);
    printf("Number of %d in list is %d\n",item,numofElem); // check why wrong
    
  //  deleteList(head);
    
 /*  head =  push(head,-1);
    printList(head);
    
    int data = pop(&head);
    printf("The popped data is %d\n",data);*/
    
    InsertNthNode(2,2,&head);
    printList(head);
     elements = count(head);
    printf(" New Count is %d\n",elements);
    
    struct LinkedList* newNode = malloc(sizeof(struct LinkedList));
    
    if (newNode != NULL)
        newNode->data = 2;
    
    SortedInsert(&head,newNode);
  //  printList(head); 
    
    RemoveDuplicates(head);
     printList(head);
    
    Reverse(&head);
    printList(head);
    
    // Test for append, Move etc
    struct LinkedList* a = BuildSimpleList(a,3);
    struct LinkedList* b = BuildSimpleList(b,3);
    
 //   append(&a,&b);
    
    MoveNode(&a,&b);
    printf("List A: \n");
    printList(a);
    printf("List B: \n");
    printList(b);
    
    // some porbelm in MoveNode - check
  //  struct LinkedList* result = SortedMerge(a,b);
  //  printList(result);
    
    
    
    return 0;
}