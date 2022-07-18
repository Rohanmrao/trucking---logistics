
void truck_disp();
int ID_gen(int l, int u);
void places_disp();  
int enterplace(int p1, int p2); 
double mobileNumber(double mb);
  
void cancel_front(double mobileNum);
void cancel_end(double mobileNum); 

void random_num(double mobileNum); 

int final_cost(int s,int distmult);
int check(int dd,int mm,int yy,int flag);
int drive_on();

typedef struct location
{
	char origin[100];
	char destination[100];
}location;  

