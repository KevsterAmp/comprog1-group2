#include<stdio.h>
	
	// struct definition
	struct students{
		char name[30];
		int age;
		char program[50];
		char year[20];
	};
	
	//main
	int main(){
	struct students student[10];
	// get the student's informations
	int i=0;
	for(i=0; i<10; i++){
		printf("Enter your name: ");
		fgets(student[i].name, 30, stdin);
		
		printf("Enter your age: ");
		scanf("%d", &student[i].age);
		getchar();
		
		printf("Enter your program: ");
		fgets(student[i].program, 50, stdin);
		
		printf("Enter your year level (Freshman, Sophomore, Junior, Senior): ");
		fgets(student[i].year, 20, stdin);
		
		//prints the informations
		printf("\nInformation for Student %d\n", i + 1);
		printf("Name: %s ", student[i].name);
        printf("Age: %d", student[i].age);
    	printf("Course: %s", student[i].program);
	    printf("Year Level: %s", student[i].year);
	    printf("\n");	
    }  
	return 0;
}


