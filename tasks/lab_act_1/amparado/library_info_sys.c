#include <stdio.h>
#include <string.h>

struct library {
    char title[20];
    char author[20];
    char borrower[20];
    int days_borrowed;
    int fine;
};
struct library lib[5];

void print_library(int i, struct library lib[]);

int main(void) {
    // init
    int choice, i = 0;
    char temp[20];

    while (1) {
        printf("\n\nWelcome to Library Information System.\n");
        printf("Input title of the book: ");
        gets(temp);

        for (int j = 0; j < 5; j++) {
            if (strcmp(temp, lib[j].title) == 0) {
                printf("Book already exists. Exiting...\n");
                print_library(i - 1, lib);
                return 0;
            }
        }

        strcpy(lib[i].title, temp);

        printf("Input author of the book: ");
        gets(lib[i].author);

        printf("Input borrower of the book: ");
        gets(temp);

        for (int j = 0; j < 5; j++) {
            if (strcmp(temp, lib[j].borrower) == 0) {
                printf("Strictly one book, one borrower policy. Exiting...\n");
                print_library(i - 1, lib);
                return 0;
            }
        }

        strcpy(lib[i].borrower, temp);

        printf("Input days borrowed of the book: ");
        scanf("%d", &lib[i].days_borrowed);

        // Fine logic
        if (lib[i].days_borrowed > 3) {
            lib[i].fine = (lib[i].days_borrowed - 3) * 5;
        }

        else if (lib[i].days_borrowed < 1) {
            printf("Error input. Exiting...\n");
            print_library(i - 1, lib);
            return 0;
        }

        else {
            lib[i].fine = 0;
        }

        // Book logic
        printf("\nBook uploaded...\n");

        if (i == 4) {
            printf("Library is full. Exiting...\n");
            print_library(i, lib);
            break;
        }

        printf("Press 0 to exit, 1 to continue: ");
        scanf("%d", &choice);
        getchar();

        if (choice == 0) {
            print_library(i, lib);
            break;
        }

        else if (choice == 1) {
            i++;
        }

        else {
            printf("Invalid input. Exiting...\n");
            break;
        }
    }
}

void print_library(int i, struct library lib[]) {
    for (int j = 0; j <= i; j++) {
        printf("\nBook %d\n", j + 1);
        printf("Title: %s\n", lib[j].title);
        printf("Author: %s\n", lib[j].author);
        printf("Borrower: %s\n", lib[j].borrower);
        printf("Days borrowed: %d\n", lib[j].days_borrowed);
        printf("Fine: %d\n", lib[j].fine);
    }
}
