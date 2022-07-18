#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "truck_server.h"
#include <time.h>

/* Things to add here - 

	User details from the employee's side 
    a̶v̶a̶i̶l̶a̶b̶l̶e̶ d̶r̶i̶v̶e̶r̶s̶ 
	a̶v̶a̶i̶l̶a̶b̶l̶e̶ t̶r̶u̶c̶k̶s̶ 
	l̶o̶c̶a̶t̶i̶o̶n̶ s̶e̶l̶e̶c̶t̶ 
	w̶e̶i̶g̶h̶t̶ l̶o̶a̶d̶ 
	a̶d̶d̶i̶t̶i̶o̶n̶a̶l̶ f̶e̶a̶t̶u̶r̶e̶s̶ n̶e̶e̶d̶e̶d̶
	t̶o̶t̶a̶l̶ c̶o̶s̶t̶ 
	fuel + repairs 
	e̶t̶a̶ 
	confirmation pemp_no 


*/
//***********************************GLOBALS***********************************************
	char name[50], cancel_choice[1];	// name : stores the name of the user 			
	int emp_no ,rm;                        // rm :mod multiplier
	int ser, tonz;                        //ser : serial number of the truck mod , tonz: weight in tons 
	int truck_choice, choice_flag = 1;  // truck_choice: displays the train alloted 

	int p1 = 0;int p2 = 0;              //p1: starting point serial number ; p2 : destination serial number 
    
	
    int dd, mm, yy;                     // day, month, year 
	int flag = 0,cout,a;                //flag and cout are counting variables , a stores value of check function


	
	int payup,dm;                       //payup:stores final cost of the trip  ; dm : distance mutliplier

	double mobileNum; double mobilenum_fordisplay;

	location loc;

	char *places[50] = {"BangaloreCity", "Mumbai", "NewDelhi", "Bijapur", "Kolhapur", "Mysore", "Badami", 
	"Chennai", "Secunderabad", "Hubli", "Hospet", "Jaipur", "Lucknow", "Solapur", "Mangalore"};

	int eta; // eta in hours
//*******************************************************************************************

int main() 

{ 
	printf("\t\t=================================================\n");
	printf("\t\t|                                               |\n");
	printf("\t\t|     --------------------------------          |\n");
	printf("\t\t|        TRUCKING LOGISTICS SYSTEM              |\n");
	printf("\t\t|     --------------------------------          |\n");
	printf("\t\t|                                               |\n");
	printf("\t\t|      _______DSA MINI PROJECT______            |\n");
	printf("\t\t|                                               |\n");
	printf("\t\t|                                               |\n");
	printf("\t\t|                                               |\n");
	printf("\t\t|                                               |\n");
	printf("\t\t=================================================\n\n\n");
	
    printf("=========================*new session*===========================\n");
	printf("    EMPLOYEE TERMINAL - LOGIN/CANCEL Pemp_no\n");
	printf("========================================================\n");
	printf("\n");
	printf("======================= LOGIN FORM =====================\n  ");
	printf("\n");
    printf("ENTER YOUR COMPANY PHONE NUMBER: ");              //User enters the mobile number
	scanf("%lf",&mobileNum);
	getchar();

	mobileNumber(mobileNum);                         //mobilenumber() is called to verify whether the entered number is 10 digit or not
	random_num(mobileNum);                           //random_num() is called to generate the random four digit number

	printf("\n");
	printf("Do you want to cancel an existing job ? (y/n): ");
	scanf("%s",cancel_choice);getchar();

	if(strcmp(cancel_choice,"y") == 0)
	{
		cancel_front(mobileNum);                      //cancel_front() is called if the user wants to cancel the previously booked tickets
	}
	printf("\n");
	places_disp();
	printf("\n-------------------------\n");
	
	printf("\n");
	printf("Enter the Sl.no of the start point: ");    // User enters the starting point
	scanf("%d",&p1); getchar();  
	strcpy(loc.origin, places[p1 - 1]);
	printf("\n");
	printf("Enter the Sl.no of the end point: ");      // User enters the end point 
	scanf("%d",&p2);getchar();
	strcpy(loc.destination, places[p2 - 1]);
	printf("\n");
	dm = enterplace(p1,p2);                           // distance  multiplier generated here 
	                                                 // enterplace() is called to verify whether the entered places are valid or not 

	printf(" \n ---------------------DATES AVAILABLE WITHIN 1 YEAR PERIOD  -------------------------\n ");
	printf("\n");
	printf("\n----------NOTE : booking date and travelling dates must have  minimum of 1 day gap------------- \n ");
	printf("\n");
	printf("Enter the  booking date  (DD/MM/YYYY) : ");         
	scanf("%d/%d/%d",&dd,&mm,&yy);//getchar();
	a=check(dd,mm,yy,flag);
	printf("%d\n",a);
	if(a == 0)                                     // executed only if the entered date is invalid 
    {
        printf("Please enter a valid date (DD/MM/YYYY format): ");
        scanf("%d/%d/%d",&dd,&mm,&yy);
		fflush(stdin);
        check(dd,mm ,yy,flag);                             // re-checking if the entered date is valid 
    }    
	fflush(stdin);
	
	

	printf("\n");
	truck_disp();
	printf("-----------------------------------------------------\n");
	printf("Proceed with %d...? \n",choice_flag);
	printf("Type 1 to accept... 2 to reject :");
	scanf("%d",&truck_choice); //getchar();
	choice_flag=2;

	if(truck_choice == 2 && choice_flag>=2)
	{
		printf("------------------------------\n");
		printf("Reallotting...\n");
		printf("Proceed with %d...? \n",choice_flag);
		printf("Type 1 to accept... 2 to reject :");
		scanf("%d",&truck_choice); //getchar();
		choice_flag=3;
	}

	if(truck_choice == 2 && choice_flag>=2)
	{
		printf("------------------------------\n");
		printf("Reallotting...\n");
		printf("Proceed with %d...? \n",choice_flag);
		printf("Type 1 to accept... 2 to reject :");
		scanf("%d",&truck_choice); //getchar();
		choice_flag=4;
	}

	if(truck_choice == 2 && choice_flag>=2)
	{
		printf("------------------------------\n");
		printf("Reallotting...\n");
		printf("Proceed with %d...? \n",choice_flag);
		printf("Type 1 to accept... 2 to reject :");
		scanf("%d",&truck_choice); //getchar();
		choice_flag=5;
	}

	// accepting employee details
	printf("\n");
	printf("-----------------------------------\n");
	printf("\n");
  	printf("Enter you Name: ");
	fflush(stdin);
  	scanf("%s",&name);getchar();
  	printf("Enter your Employee no.: ");
	fflush(stdin);
  	scanf("%d",&emp_no);getchar();  	
	printf("1.LONG TRAILER  | 2. SHORT BED | 3. SLEEPER CABIN | 4.EXTRA FUEL TANKS  \n"); // selection of additional features
	printf("_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_\n");
  	printf("Select the add-ons by entering the number next to it: ");
  	scanf("%d",&ser);getchar();
  	printf("Weight load in TONS: ");
  	scanf("%d",&tonz);getchar();
	fflush(stdin);
	payup = final_cost(ser,dm);                   // final_cost() is called to calculate the final amount 

	switch (dm){
		case 1:
			{eta = 10; break;}
		case 2:
			{eta = 13; break;}
		case 3:							// ETA calculation in hours
			{eta = 15; break;}
		case 4:
			{eta = 18; break;}
	}

	// bill displaying data based on info collected from user
	printf("\n");
	printf("\n----------DETAILS------------\n");
	printf("\n");
	printf("Name:");
	puts(name);
	printf("Employee No. : %d\n",emp_no);
	mobilenum_fordisplay = mobileNumber(mobileNum);
  	printf("Start of Trip : %d/%d/%d\n",dd,mm,yy);
	printf("Mobile Phone: %.0f\n",mobilenum_fordisplay);
	printf("From: %s\n", loc.origin);
	printf("To: %s\n", loc.destination);
	printf("Truck: %d\n",choice_flag-1);
  	printf("JOB Status: INITIATED. ETA : %d hours\n",eta);
	printf("Total Amount: %d\n",payup);
	drive_on();
    printf("\n-------------------------------------------------");

	printf("\n Do you want to cancel the scheduled job ? (y/n): ");
	scanf("%s",cancel_choice);getchar();

	if(strcmp(cancel_choice,"y") == 0)
	{
		cancel_end(mobileNum);
	}
	else
	{
		printf("\n");
		printf("Thank You\n");
		printf("*******************************************************\n");
		printf("*******************************************************\n");
		fflush(stdin);
		fflush(stdout);
		main(); // running the main fucntion again for a rerun;
	}

}
