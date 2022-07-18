#include <stdio.h>
#include <string.h>
#include "truck_server.h"
#include <time.h>
#include <stdlib.h>

// Defnition for all the functions that will land on the opening page  

double mobileNumber(double mb)                                       //Checks whether the mobilenumber entered is 10 digit or not
{
    if (mb < 1000000000 || mb > 9999999999)
    {
        printf("\n Please enter only 10 digits... \n");
		exit(0);    
    }
    return mb;
}

void random_num(double mob)                                         // Generates the 4 digit Random number between 1000 and 9999
{
    int i = 0;
    
    printf("\n");
    printf("                       SESSION ID IS  : ");
    int otp, trials = 0; 
	int a = ID_gen(1000,9999);
    printf("%d\n",a);
	printf("\n");
    printf("                       ENTER THE SESSION ID : ");
    scanf("%d",&otp);
	getchar();
    
    if(a==otp)
    {
        printf("\n");
		printf("      WELCOME TO OUR SYSTEM !! YOUR LOGIN IS SUCCESSFUL\n");
	 
        FILE *fp;
	    fp=fopen("logindetails.txt","w");
        fprintf(fp,"%.0f",mob);
        fclose(fp);

    }    
    else 
    {
        printf("             SORRY !!!!  LOGIN IS UNSUCCESSFULL\n");   
    }
}

void places_disp()                                       // This is the function that will show all the available places 
{
	
	printf("Here are the available locations:\n");
	

	FILE* places_disp;
    int display;
 
    
    places_disp = fopen("places.txt", "r");            // Loop to extract all characters
 
    
    while (1) {
        // reading file
        display = fgetc(places_disp);
 
        // end of file indicator
        if (feof(places_disp))
            break;
 
        // displaying every characters
        printf("%c", display);
    }
	
}

int enterplace(int p1,int p2)                          //Function to take the input for two listed delivery locations
{
	int distance_val = 0, dist_multiplier, flag = 0;
	if(p2 > p1){                                      //Loop to verify whether entered value for locations are valid or not
		distance_val = p2-p1;
		flag++;
	}
	else if (p1 >p2){
		distance_val = p1-p2;
		flag++;
	}
	else {
		distance_val = 0;
		flag++;
	}

	if((p1 >15 && p2 >15) || (p2 <=0 && p1 <=0))
	{
		printf("Invalid inputs..");
	}
	
	if(distance_val >= 1 && distance_val <=5 && flag!=0)
	{
		dist_multiplier = 2;
	}
	else if(distance_val >=6 && distance_val <=10 && flag!=0)
	{
		dist_multiplier = 3;
	}
	else if(distance_val >=11 && distance_val <15 && flag!=0)
	{
		dist_multiplier = 4;
	}
	return dist_multiplier ; 
}

int flag;                                               //  a counting variable

int check(int dd,int mm ,int yy)                       // validating the entered dates assuming all months have only 30 days
{     

    time_t t;                                         // time_t  is a type suitable for storing calendar time
    t = time(NULL);
    struct tm tm = *localtime(&t);                   //accessing local time
    flag=0;

                                                    //tm.tm_year+1900 : current year  ||  tm.tm_mon+1 : current month ||   tm.tm_mday: current day of the month

    if(yy==(tm.tm_year+1900))                      // checking if the user entered the current year
    {
       if(mm==(tm.tm_mon+1))                      // checking if the enter month matches the current the month number
       {
           if(dd>tm.tm_mday && dd<=30)
            {
                return flag++;
            }
              
        }

       if (mm>(tm.tm_mon+1) && mm<=12)          // since the year is same , month number accepted must be greater than current month number and less than 12
        {
            if(dd>=1 && dd<=30)
            {
               return flag++;
            }
        }
    
    }

    if (yy==(tm.tm_year+1901))                 // checking if the entered  year is the next year and the following is executed when user enters the next year
    {
       if(mm==(tm.tm_mon+1))                  // checking if the month number for the next year matches the current month number 
       {
           if(dd<=tm.tm_mday && dd>=1)       //since tickets are availble for 1 year period , the  dates accepted will range from (1 to current date number)
              {
                 return  flag++;
              }
              
        }

        if (mm<(tm.tm_mon+1) && mm<=12)     // user enterd month must be less than the current month number to satisfy 1 year booking period
        {
            if(dd>=1 && dd<=30)             // all date numbers are vaild 
            {
               return flag++;
            }
        }
    }
      
}  

void truck_disp()                           // Displays the available truck details
{
    printf("Here are the available trucks for the trip...\n");
	printf("___(The deprature timings are mentioned along with the location and driver details)___ \n");
	printf("-----------------------------------------------------------------------\n");

        char *train_db[25] = {"","MangalaLakshadweepExpress","PrashantiExpress",
                            "SharavatiExpress","WaingangaSuperfastExpress","KondaveeduExpress"
                            ,"RaniChennammaExpress","JanShatabdiExpress","RajyaRaniExpress"
                            ,"SiddagangaIntercity","VishwamanavaExpress","ChamundiExpress"
                            ,"KaveriExpress","BasavaExpress","GolGumbazExpress","TippuSuperfastExpress"    
                            ,"DurontoExpress","GaribRathExpress","MalgudiExpress","GomateshwaraExpress"
                           ,"SamparkKrantiExpress","AmaravatiExpress"
						   ,"PanchagangaExpress","NightQueenPassenger","HumsafarExpress"
                        };

		char *d_names[25] = {"Lokesh", "Umesh","Ravi","Anthony","Vinod","Nikhil","Rajesh","Raj","Mahesh","Ganesh","Ramesh","Virat","Manish",
									"Vikram","Joseph","Amritha","Shanti","Darlene","Parvati","Surya","Smrithi","Rupali","Jayamma","Ananya","Aditi"};

		char *loc[25] = {"Zone A1","Zone A2","Zone A3","Zone A4","Zone A5",
							"Zone B1","Zone B2","Zone B3","Zone B4","Zone B5",
							"Zone C1","Zone C2","Zone C3","Zone C4","Zone C5",
							"Zone D1","Zone D2","Zone D3","Zone D4","Zone D5",
							"Zone E1","Zone E2","Zone E3","Zone E4","Zone E5"};
						
		int time_hr[25] = {1,2,3,4,5,6,7,8,9,10,11,12,11,10,9,8,7,6,5,4,3,2,1,4,5};
		int time_min[25] = {10,15,20,30,35,40,45,50,40,35,30,25,20,15,10,10,15,20,25,30,30,30,30,45,45};   // database of times 

		int ind1,ind2,ind3, u=26,l=0;
		 srand(time(0)); 
	
        for(int i = 0; i < 5; i++)
        {
                   
            ind1 = ((rand() % (u - l + 1)) + l);
			ind2 = ((rand() % (u - l + 1)) + l);
			ind3 = ((rand() % (u - l + 1)) + l);
			int hr = time_hr[ind1];
			int min = time_min[ind1];
            printf("%d ",i+1);
            printf("%s\tLoading Station: %s\t Driven by: %s\t\t ",train_db[ind1],loc[ind2],d_names[ind3]);
            if(i%2 == 0)
            {
                printf("at %d:%d AM\n",hr,min);
            }
            else if( i%2 != 0)
            {
                printf("at %d:%d PM\n",hr,min);
            }
        }
}

int cout;                             //A counting variable

int final_cost(int s, int distmult)      //Calculates the final trip cost based on vaild input
{	
	
    cout =0;
                                    //truck mod multipliers: 1- rs 2000 | 2 - rs 2500 |3 - rs 1500 |4 - rs 1000
  if (s>=1 && s<=4)
  { 
	cout++;
    if(s==1)
    {
      return (2500*s*distmult*10);
    }   
    if(s==2)
    {
      return (2000*s*distmult*10);
    }  
    if(s==3)
    {
      return (1500*s*distmult*10);
    }   
    else
    {
      return (1000*s*distmult*10);
    }     
  } 
                                    // formula used to calculate the cost : final price = distance_multiplier * number of tickets * reservation multiplier 
                                   // mod multipliers: 1- rs 2500 | 2 - rs 2000 |3 - rs 1500 |4 - rs 1000
  
}

int drive_on()                   // displays real time at which the job was scheduled
{
 
    time_t t;
    t = time(NULL);
    struct tm tm = *localtime(&t); 
    printf("This job was scheduled on: %d-%d-%d", tm.tm_mday, tm.tm_mon+1, tm.tm_year+1900);
	printf("\n");
    
}

void cancel_end(double mobileNumber)  // Function to cancel a job at the end of the transaction
{
	int a, otp, otp_enter;

	printf("	TO PROCEED TO CANCELLATION, PRESS '1':  \n");    // EMPLOYEE CONFIRMS WHETHER HE WANTS TO PROCEED TO CANCELLATION.
	scanf("%d", &a);
	if(a == 1)
	{
		int l = 1000, u = 9999, otp, trials = 0;

		//srand(time(0)); 
		otp = ID_gen(l,u);          //ENSURING THAT THE RANDOM ID GENERATED WILL CONSIST OF 4 DIGITS ONLY.
		printf("	SESSION ID IS   : %d\n", otp);
		printf("\n");
		printf("	ENTER SESSION ID : ");
		scanf("%d", &otp_enter);
		printf("\n");
		                            
		while((otp_enter != otp) && (trials <= 2))
		{
			printf("	INVALID ID! PLEASE TRY AGAIN \n");
			printf("\n");
			printf("	ENTER YOUR ID: ");
			scanf("%d", &otp_enter);
			trials++;
		}
		                           //CHECKING IF THE NUMBER ENTERED MATCHES THE GENERATED OTP
		if(otp_enter == otp)
		{
			printf("\n");
			printf("	THE JOB HAS BEEN CANCELED! \n");
		}
		else
		{
			printf("\n");
			printf("	UNABLE TO CANCEL. CONTACT THE ADMINISTRATOR \n");
		}
		
	}
	printf("	THANK YOU! \n");
}





int ID_gen(int l,int u) // Generates the SESSION LOGIN ID
{
	srand(time(0));
	return ((rand() % (u - l + 1)) + l);

}


void cancel_front(double mobileNum)  // Function to cancel previously scheduled jobs
{
	FILE *fp; 
	
	                                //ATTEMPT TO OPEN THE TEXT FILE
	fp = fopen("logindetails.txt","r");
	                               //CHECKING IF THE FILE EXISTS
	if(fp == NULL)
	{
		printf("	FILE DOES NOT EXIST! \n");
	}

	                              //OPENING THE FILE AND PROCEEDING IF FILE EXISTS
	else
	{
		double ph;

		printf("PLEASE ENTER THE COMPANY PHONE NUMBER:  \n");   //PROMPTING USER TO ENTER THE PHONE NUMBER
		scanf("%lf", &ph);
		if(ph==mobileNum)        //CHECKING IF THE ENTERED PHONE NUMBER MATCHES THAT PRESENT IN THE TEXT FILE
		{

			                    //GENERATING AN ID
			int otp, otp_enter;
			int trials = 0;

			//srand(time(0)); 
			otp = ID_gen(1000,9999); //ENSURING THAT THE ID GENERATED WILL CONSIST OF 4 DIGITS ONLY.
			printf("	ID: %d\n", otp);
			printf("\n");

			                         //PROMPT FOR USER TO ENTER THE OTP
			printf("	ENTER YOUR ID: ");
			scanf("%d", &otp_enter);

			                        //WE SHALL LIMIT THE NUMBER OF TRIALS OF OTP ENTRY TO 4.
			while((otp_enter != otp) && (trials <= 2))
			{
				printf("	INVALID ID! PLEASE TRY AGAIN \n");
				printf("\n");
				printf("	ENTER YOUR ID: ");
				scanf("%d", &otp_enter);
				trials++;
			}

			                       //CHECKING IF THE NUMBER ENTERED MATCHES THE GENERATED ID
			if(otp_enter == otp)
			{
				printf("\n");
				printf("	JOB HAS BEEN CANCELED! \n");
			}
			else
			{
				printf("\n");
				printf("	UNABLE TO CANCEL. CONTACT THE ADMINISTRATOR \n");
			}
		
		}

		else                       //IF PHONE NUMBER ENTERED DOES NOT MATCH THAT PRESENT IN THE TEXT FILE
		{
			printf("\n");
			printf("	INVALID PHONE NUMBER! \n");
		}

		fclose(fp);
	}

	printf("\n");
	printf("	THANK YOU! \n");
}




