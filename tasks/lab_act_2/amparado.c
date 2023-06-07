#include <stdio.h>
#include <conio.h>

struct seats {
    struct rows {
        char val;
    };
    struct rows row[4];
};
struct seats seat[5];

void print_seating();
int seating_check();


int main(void) {
    // initalize values
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 4; j++) {
            seat[i].row[j].val = j + 65;
        }
    }
    int x;
    char y;

    print_seating();
    while(1) {
        if (seating_check() == 0) {
            printf("All seats are occupied. Exiting program");
            break;
        }

        printf("Send seating here (Press 0 to exit): ");
        scanf("%d%c", &x, &y);
        
        if (seat[x - 1].row[y - 65].val == 'X') {
            printf("Seat is already occupied. Try again");
        }

        else if (seat[x -1].row[y - 65].val == y) {
            seat[x - 1].row[y - 65].val = 'X';        
            print_seating();
        }    

        if (x == 0) {
            printf("Exiting program");
            break;
        }
        printf("\n\n");
    }
}


void print_seating() {
    for (int i = 0; i < 5; i++) {
        printf("%d\t", i + 1);
        for (int j =0; j < 4; j++) {
            printf("%c\t", seat[i].row[j].val);
        }
        printf("\n");
        }
}


int seating_check() {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 4; j++) {
            if (seat[i].row[j].val != 'X') {
                return 1;
            }
        }
    }
    return 0;
}    