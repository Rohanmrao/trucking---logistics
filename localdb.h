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