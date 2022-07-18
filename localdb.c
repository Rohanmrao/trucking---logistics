// local db implementation using a linked list 

#include <stdio.h>
#include <stdlib.h>
#include "truck_server.h"


typedef struct node{
    int key;
    struct node *next;
}NODE;

typedef struct queue{

    struct node *front , *rear;
}Q;

NODE *create_node(int);
Q *create_queue();
void schedule_job(Q*,int);
void delete_job(Q*);
void display(Q*);

NODE *create_node(int key_in){

    NODE *temp = malloc(sizeof(NODE));
    temp->key = key_in;
    temp->next = NULL;

    return temp;
    
}
Q *create_queue(){

    Q *q = malloc(sizeof(Q));
    q->front = q->rear = NULL;

    return q;
}

void schedule_job(Q* q, int k)
{

    printf("Enqueing %d\n",k);
    // Create a new temporary node
    Q *temp = create_node(k);
  
    // If queue is empty, then new node is front and rear both
    if (q->front == NULL && q->rear == NULL) {
        q->front = q->rear = temp;
        return;
    }
  
    // Add the new node at the end of queue and change rear
    q->rear->next = temp;
    q->rear = temp;
    q->rear->next = NULL;
}

void delete_job(Q *q)
{
    // If queue is empty, return NULL.
    if (q->front == NULL && q->rear == NULL){

        printf("Empty\n");
        return;
    }
  
    // Store previous front and move front one node ahead
    NODE *temp = q->front;
  
    q->front = q->front->next;
  
    // If front becomes NULL, then change rear also as NULL
    if (q->front == NULL)
        q->rear = NULL;
  
    printf("Deleting %d\n",temp->key);
    free(temp);
}

void display(Q *q){

    NODE *temp = q->front; // this will traverse the queue 
    temp = q->front;

    while (temp != NULL){
        
        temp = q->front;
        printf("%d\n",temp->key);
        q->front = q->front->next;
        
    }

    free(temp);
    temp = NULL;
}

int main(){

    Q *q = create_queue();

    schedule_job(q,5);
    schedule_job(q,7);
    schedule_job(q,9);

    delete_job(q);

    display(q);

    return 0;
}

main();