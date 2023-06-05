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
int checker(char book[], char borrower[], struct library lib[]);
int compute_fine(int day);

int main(void) {
    int choice, i = 0;
    char temp_book[20], temp_borrower[20];

    while (1) {
        printf("\n\nWelcome to Library Information System.\n");
        printf("1. Add book\n");
        printf("2. Print library\n");
        printf("3. Exit\n");
        scanf("%d", &choice);
        printf("\n\n");
        getchar();

        if (choice == 1) {
            printf("Input title of the book: ");
            gets(temp_book);

            printf("Input author of the book: ");
            gets(lib[i].author);

            printf("Input borrower of the book: ");
            gets(temp_borrower);

            printf("Input days borrowed of the book: ");
            scanf("%d", &lib[i].days_borrowed);

            // Check if book/borrower already exists
            if (checker(temp_book, temp_borrower, lib)) {
                continue;
            }
            else {
                strcpy(lib[i].title, temp_book);
                strcpy(lib[i].borrower, temp_borrower);
            }
            
            lib[i].fine = compute_fine(lib[i].days_borrowed);
        }

        else if (choice == 2) {
            print_library(i - 1, lib);
        }

        else if (choice == 3) {
            return 0;
        }

        else {
            printf("Invalid input\n\n");
        }

        if (i >= 5) {
            printf("Library is full.\n");
            print_library(i - 1, lib);
        }
        i++;
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

int checker(char book[], char borrower[], struct library lib[]) {
    for (int i = 0; i < 5; i++) {
        if (strcmp(book, lib[i].title) == 0) {
            printf("Book already exists.");
            return 1;
        }
    }

    for (int i = 0; i < 5; i++) {
        if (strcmp(borrower, lib[i].borrower) == 0) {
            printf("Strictly one book, one borrower policy.");
            return 1;
        }
    }   
    return 0;
}

int compute_fine(int day) {
    if (day > 3) {
        return (day - 3) * 5;
    }
    else {
        return 0;
    }
}
