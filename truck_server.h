
void truck_disp();
int ID_gen(int l, int u);
void places_disp();  
int enterplace(int p1, int p2); 
double mobileNumber(double mb);
  
void cancel_front(double mobileNum);
void cancel_end(double mobileNum); 

void random_num(double mobileNum); 

int final_cost(int s,int distmult,int weight);
int check(int dd,int mm,int yy,int flag);
int drive_on();

typedef struct location
{
	char origin[100];
	char destination[100];
}location;  

typedef struct node{
    int key;
    struct node *next;
}NODE;

typedef struct queue{

    struct node *front , *rear;
}Q;

// stack implementation 
NODE *create_node(int);
Q *create_queue();
void schedule_job(Q*,int);
void delete_job(Q*);
void display_schedule(Q*);

// Linked list implememtation - Nehal 
typedef struct node_d
{
	int licence_num;
    int driver_age;
	int driver_id;
	struct node_d *next;
}NODE_D;
// creating the next pointer

typedef struct llist
{
	NODE_D *head;
}LLIST;
// creating the head pointer

int countNodes(LLIST *pl);
void add_driver(LLIST *pl,int lnum,int d_age,int d_id);
void display_drivers_drivers(LLIST *pl);
void initList(LLIST *pl);
