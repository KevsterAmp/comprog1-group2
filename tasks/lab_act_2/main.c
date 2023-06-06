#include <stdio.h>
#include <conio.h>

struct seats {
    struct rows {
        char column;
        char true_col;
    };
    struct rows row[4];
};

struct seats seat[5];
void print_seating();

int main(void) {
    // initalize seats
    for (int i = 1; i <= 5; i++) {
        for (int j = 0; j < 4; j++) {
            seat[i].row[j].true_col = j + 65;
            seat[i].row[j].column = j + 65;
        }
    }

    for (int i = 1; i <= 5; i++) {
        printf("%d\t", i);
        for (int j =0; j < 4; j++) {
            printf("%c\t", seat[i].row[j].column);
        }
        printf("\n");
        }
    printf("\n");
    int x, flag = 1;
    char y;

    while(1) {
        if (flag == 0) {
            printf("All seats are occupied\n\n");
            break;
        }
        flag = 0;
        printf("Send seating here (Press 0 to exit): ");
        scanf("%d%c", &x, &y);
        
        for (int i = 1; i <= 5; i++) {
            for (int j = 0; j < 4; j++) {
                if ((x == i) && (seat[i].row[j].true_col == y)) {
                    if (seat[i].row[j].column == 'X') {
                        printf("Seat is already taken\n");
                        continue;
                    }
                    seat[i].row[j].column = 'X';        
                    print_seating();
                    printf("\n\n");
                }       
                if (seat[i].row[j].column != 'X') {
                    flag = 1;
                }                 
            }
        }

        if (x == 0) {
            printf("Exiting program\n\n");
            break;
        }
    }
}

void print_seating() {
    for (int i = 1; i <= 5; i++) {
        printf("%d\t", i);
        for (int j =0; j < 4; j++) {
            printf("%c\t", seat[i].row[j].column);
        }
        printf("\n");
        }

}