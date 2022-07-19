#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "truck_server.h"
#include <time.h>

#pragma GCC diagnostic ignored "-Wimplicit-function-declaration"
#pragma GCC diagnostic ignored "-Wincompatible-pointer-types" 
#pragma GCC diagnostic ignored "-Wint-conversion"

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

	char *places[50] = {"Bangalore", "Mysore", "Hubli", "Mangalore", "Chennai", "Hyderabad", "Bijapur", 
	"Mumbai", "Goa", "Noida", "Meerut", "Agra", "Lucknow", "Gurgaon", "Jammu"};

	int eta; // eta in hours

	int job_no;

	int runagain = 1;

	int entry_choice;

	int ch,x,lnum,d_age,posi,d_id; // variables for the linked list function
	char ch1;
	int driv_total;

//*******************************************************************************************

int main() 

{ 
	Q *q = create_queue();
	struct Node* head = NULL;
    NODE_D *pl = createNode(lnum,d_age,d_id);

	while(runagain)
	{
		printf("1. Add a new driver | 2. Log system | 3. Job Schedule\n");
		scanf("%d",&entry_choice);

		switch(entry_choice)
		{

			case 1:{

				x=1;
				while(x)
				{
						printf("Enter 1 for adding and 2 for displaying and exiting \n");
						scanf("%d",&ch);
						if(ch == 1)
						{
							printf("Enter Licence Number \n");
							scanf("%d",&lnum);
							printf("Enter Driver Age \n");
							scanf("%d",&d_age);
							printf("Enter Driver ID \n");
							scanf("%d",&d_id);
							add_driver(pl,lnum,d_age,d_id);
							driv_total = countNodes(pl);
							printf("Driver count :- %d\n",driv_total);
						}
						else if(ch == 2)
						{
							display_drivers(pl);
							printf("Driver count :- %d\n",driv_total);
							x--;
						}
				}

				break;
			}

			case 2:
			{

			




				printf("\t\t=================================================\n");
				printf("\t\t|                                               |\n");
				printf("\t\t|     --------------------------------          |\n");
				printf("\t\t|        TRUCKING LOGISTICS SYSTEM              |\n");
				printf("\t\t|     --------------------------------          |\n");
				printf("\t\t|                                               |\n");
				printf("\t\t|      _______DSA MINI PROJECT______            |\n");
				printf("\t\t|              Rohan And Nehal                  |\n");
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
					cancel_front(mobileNum);
					delete_job(q);
					printf("Jobs in progress...\t");
					display_schedule(q);  
					runagain--;                    //cancel_front() is called if the user wants to cancel the previously booked tickets
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
				payup = final_cost(ser,dm,tonz);                   // final_cost() is called to calculate the final amount 

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

				job_no++;
				schedule_job(q,job_no);
				

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
				printf("JOB Status: INITIATED. JOB NO. %d\tETA : %d hours\n",job_no,eta);
				printf("Total Amount: %d\n",payup);
				drive_on();


				printf("\n Do you want to cancel the scheduled job ? (y/n): ");
				scanf("%s",cancel_choice);getchar();

				if(strcmp(cancel_choice,"y") == 0)
				{
					cancel_end(mobileNum);
					delete_job(q);
					printf("Job cancelled... Current jobs are...\n");
					display_schedule(q);
				}
				else
				{
					printf("Thank You\n");
					printf("*******************************************************\n");
					printf("*******************************************************\n");
					printf("Run a new terminal ? (1/0)\t"); scanf("%d",&runagain);
					if(runagain == 0)
					{
						printf("\nJobs in progress...\n");
						display_schedule(q);
						runagain--;}

					fflush(stdin);
					fflush(stdout);
					break;

					
			}

			case 3:{

				printf("ONGOING JOBS (IDENTIFIED BY JOB NO.) - \t");				
				display_schedule(q);
				break;
			}

		}

	}	

		
	}

	return 0;

}

		

