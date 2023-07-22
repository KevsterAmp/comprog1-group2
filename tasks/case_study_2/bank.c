#include <stdio.h>
#include <conio.h> // Include conio.h for getch()
#include <string.h>

struct users {
    int id;
    char account_number[6];
    int pin[4];
    float balance;
};
struct users user[3];
struct users logged_user;

void init();
int get_data_from_file(FILE* file, char input_acc_num[6]);
int second_screen();

int main() {
    FILE* fptr;
    char input_account_num[6];
    int input_pin[10];
    fptr = fopen("accounts.dat", "r+");

    if (fptr == NULL) {
        fclose(fptr);
        fptr = fopen("accounts.dat", "ab");
        init();
        for (int i = 0; i < 3; i++) {
            fwrite(&user[i], sizeof(struct users), 1, fptr);
        }
        fclose(fptr);
        printf("Data appended successfully. Kindly run the program again.\n");
        return 0;
    }


    while (1) {
        printf("Enter account number: ");
        scanf("%s", input_account_num);

        // find and load account, pin, and balance in the file
        if (get_data_from_file(fptr, input_account_num)) {
            
            // Check if the entered PIN matches the stored PIN
            int pin_matched = 1;
            printf("Enter PIN: ");

            for (int i = 0; i < 10; i++) {
                char ch = getch(); // Hide the PIN by reading character without echoing
                if (ch == '\n' || ch == '\r')
                    break;
                input_pin[i] = ch - '0';
                printf("*");
                if (i > 3)
                    pin_matched = 0;
            }
            printf("\n");
            for (int i = 0; i < 4; i++) {
                if (input_pin[i] != logged_user.pin[i]) {
                    pin_matched = 0;
                    break;
                }
            }

            if (pin_matched) {
                int temp;
                temp = second_screen();
                break;
            }

            else {
                printf("Invalid PIN\n");
            }
            break;
        } 

        else {
            printf("Account not found\n");
        }
    }
    fclose(fptr);
    return 0;
}

void init() {
    strcpy(user[0].account_number, "12345");
    user[0].id = 0;
    user[0].pin[0] = 1;
    user[0].pin[1] = 9;
    user[0].pin[2] = 9;
    user[0].pin[3] = 7;
    user[0].balance = 1000;

    strcpy(user[1].account_number, "67890");
    user[1].id = 1;
    user[1].pin[0] = 1;
    user[1].pin[1] = 2;
    user[1].pin[2] = 3;
    user[1].pin[3] = 4;
    user[1].balance = 0;

    strcpy(user[2].account_number, "10101");
    user[2].id = 2;
    user[2].pin[0] = 0;
    user[2].pin[1] = 0;
    user[2].pin[2] = 0;
    user[2].pin[3] = 0;
    user[2].balance = 5000;
}

int get_data_from_file(FILE* file, char input_acc_num[6]) {
    int found = 0;

    rewind(file);
    while (fread(&logged_user, sizeof(struct users), 1, file)) {
        if (strcmp(logged_user.account_number, input_acc_num) == 0) {
            found = 1;
            break;
        }
    }
    return found;
}

int second_screen() {
    char input;
    float deposit;
    int withdraw;
    struct users temp;
    FILE* file;

    while (1) {
        file = fopen("accounts.dat", "r+");
        rewind(file);
        printf("Welcome to PUP Online Banking System\n\n");
        printf("0. Exit online banking system\n");
        printf("1. Balance Inquiry\n");
        printf("2. Deposit\n");
        printf("3. Withdraw\n");

        printf("Press the number of your choice.: ");
        scanf(" %c", &input);

        if (input == 48) {
            fclose(file);
            return 0;
        }
        
        else if (input == 49)
            printf("Balance remaining is: %.2f\n", logged_user.balance);

        else if (input == 50) {
            printf("Input amount to deposit: ");
            scanf("%f", &deposit);

            logged_user.balance += deposit;

            // Change the struct in the account.dat
            rewind(file);
            while(fread(&temp, sizeof(struct users), 1, file)) {
                if (strcmp(temp.account_number, logged_user.account_number) == 0) {
                    fseek(file, logged_user.id * sizeof(struct users), SEEK_SET);
                    fwrite(&logged_user, sizeof(struct users), 1, file);
                    break;
                }
            }
        }


        else if (input == 51) {
            printf("Input amount to withdraw: ");
            scanf("%d", &withdraw);
            if (logged_user.balance < withdraw) {
                printf("INVALID ACTION\n");
                return 1;
            }
            logged_user.balance -= withdraw;

            //change struct in the acccount.dat
            rewind(file);

            while(fread(&temp, sizeof(struct users), 1, file)) {
                if (strcmp(temp.account_number, logged_user.account_number) == 0) {
                    fseek(file, logged_user.id * sizeof(struct users), SEEK_SET);
                    fwrite(&logged_user, sizeof(struct users), 1, file);
                    break;
                }
            }
        }

        else {
            printf("Invalid input. Try again\n\n");
        }
        printf("\n\n\n");

    }
    fclose(file);
}