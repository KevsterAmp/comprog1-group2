#include<stdio.h>

struct Library{
	char title[50];
	char author[50];
	char borrower[50];
	int daysBorrowed;
};

//main
int main(){
	struct Library informations;
	//gets the information required
	float fee=5.00;
	float charge;
	int answer;
	
	do{
		printf("\nEnter the book's title: " );
		fgets(informations.title, 50, stdin);
		
		printf("Enter the book's author: ");
		fgets(informations.author, 50, stdin);
		
		printf("Please enter the name of the borrower: ");
		fgets(informations.borrower, 50, stdin);
		
		printf("How many days did you borrow the book? ");
		scanf("%d", &informations.daysBorrowed);
		getchar();
		
		if(informations.daysBorrowed <= 3){
			printf("Please pay the amount of %.2f with no additional charge. Thank you for returning the book on time.\n", fee);
			charge = 0.0;
		}
		else{
			int extraDays= informations.daysBorrowed - 3;
            charge= extraDays * fee;
            printf("You are charge for an additional fee of %.2f. Thank you for returning the book.", charge);	
		}
		printf("\n----------------------------------------------------------------------------------");
		printf("\n\nPLEASE ACKNOWLEDGE YOUR OFFICIAL RECEIPT!\n");
		printf("Book Title: %s", informations.title);
		printf("Book Author: %s", informations.author);
		printf("Book Borrower: %s", informations.borrower);
		printf("Total Fee: %.2f", fee + charge);
		  
	    printf("\nPress 1 for the next returner. Press 0 to exit.");
	    scanf("%d", &answer);
        getchar();
	}while(answer==1);
	
	return 0;
}
