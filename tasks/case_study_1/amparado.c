#include <stdio.h>
#include <conio.h>
#include <string.h>

struct resto {
    struct items {
        char type[20];
        char item_code[10];
        float price;
        char description[30];
        int quantity;
        float total_item_amt;
    };
    struct items item[10]; 
    float total_bill;
    float discount;
    float net_bill;
};
struct resto restaurant;

void init_menu();
void print_menu(char choice);
char choose_menu();
void print_cart();
void bill_out(int table_num);
void clear_input_buffer();

int main(void) {  
    char choice, temp_item_code[10], bill_out_choice;
    int flag = 0, table_num;
    init_menu(); // Call the menu function to populate the items

    while (1) {
        printf("PLEASE INPUT TABLE NUMBER: ");
        if (scanf("%d", &table_num) != 1 || table_num < 0) {
            clear_input_buffer();
            printf("Invalid input, try again\n\n");
        }

        else {
            getchar();
            break;
        }
    }

    while (1) {
        printf("\n\nWELCOME TO MASARAP-KUMAIN RESTAURANT\n\nMasarap-Kumain restaurant offers:\n\n");
        choice = choose_menu();
        getchar();
        while (1) {
            print_menu(choice);
            printf("What would you like to eat? (Type X to choose another type of serving)\n");
            gets(temp_item_code);

            if (strcmp(temp_item_code, "X") == 0) {
                printf("\n\n");
                break;
            }

            for (int i = 0; i < 10; i++) {
                if (strcmp(temp_item_code, restaurant.item[i].item_code) == 0) {
                    while (1) {
                        printf("How many would you like to buy? ");
                        if (scanf("%d", &restaurant.item[i].quantity) != 1 || restaurant.item[i].quantity <= 0) {
                            clear_input_buffer();
                            printf("Invalid input, try again\n\n");
                        }
                        else {
                            printf("\n\n");
                            restaurant.item[i].total_item_amt = restaurant.item[i].quantity * restaurant.item[i].price;
                            flag = 1;
                            break;
                        }
                    }
                    break;
                }
            }

            if (flag == 0) {
                printf("Invalid input, try again\n\n");
            }

            else {
                print_cart();
                getchar();
                while (1) {
                    printf("Bill out (y/n)? ");
                    bill_out_choice = getchar();
                    clear_input_buffer();
                    if (bill_out_choice == 'y') {
                        // call bill out function
                        bill_out(table_num);
                        return 0;
                    }
                    else if (bill_out_choice == 'n') {
                        printf("\n\n");
                        break;
                    }
                    else {
                        printf("Invalid Input. Try again\n\n");
                    }
                }
            }
        }

        if (strcmp(temp_item_code, "X") == 0) {
        continue;
        }

    }
}

void init_menu() {
    strcpy(restaurant.item[0].type, "Single Serving");
    strcpy(restaurant.item[0].item_code, "JR010");
    strcpy(restaurant.item[0].description, "Java Rice");
    restaurant.item[0].price = 50;

    strcpy(restaurant.item[1].type, "Single Serving");
    strcpy(restaurant.item[1].item_code, "PR030");
    strcpy(restaurant.item[1].description, "Pork Steak");
    restaurant.item[1].price = 120;

    strcpy(restaurant.item[2].type, "Single Serving");
    strcpy(restaurant.item[2].item_code, "VE070");
    strcpy(restaurant.item[2].description, "Chopsuey");
    restaurant.item[2].price = 100;

    strcpy(restaurant.item[3].type, "Single Serving");
    strcpy(restaurant.item[3].item_code, "B210");
    strcpy(restaurant.item[3].description, "Ice Tea");
    restaurant.item[3].price = 35;

    strcpy(restaurant.item[4].type, "Package Serving");
    strcpy(restaurant.item[4].item_code, "Pack1");
    strcpy(restaurant.item[4].description, "Package1");
    restaurant.item[4].price = 320;

    strcpy(restaurant.item[5].type, "Package Serving");
    strcpy(restaurant.item[5].item_code, "Pack2");
    strcpy(restaurant.item[5].description, "Package2");
    restaurant.item[5].price = 420;

    strcpy(restaurant.item[6].type, "Package Serving");
    strcpy(restaurant.item[6].item_code, "Pack3");
    strcpy(restaurant.item[6].description, "Package3");
    restaurant.item[6].price = 500;

    strcpy(restaurant.item[7].type, "Group Serving");
    strcpy(restaurant.item[7].item_code, "FG1");
    strcpy(restaurant.item[7].description, "Family Group Serving");
    restaurant.item[7].price = 550;

    strcpy(restaurant.item[8].type, "Group Serving");
    strcpy(restaurant.item[8].item_code, "BG");
    strcpy(restaurant.item[8].description, "Barkada Group Serving");
    restaurant.item[8].price = 650;

    strcpy(restaurant.item[9].type, "Group Serving");
    strcpy(restaurant.item[9].item_code, "FG2");
    strcpy(restaurant.item[9].description, "Fiesta Group Serving");
    restaurant.item[9].price = 750;

    for (int i = 0; i < 10; i ++) {
        restaurant.item[i].quantity = 0;
    }
}

void print_menu(char choice) {
    int start, stop;
    if (choice == 'a') {
        start = 0;
        stop = 4;
    }
    else if (choice == 'b') {
        start = 4;
        stop = 7;
    }
    else if (choice == 'c') {
        start = 7;
        stop = 10;
    }

    printf("%-10s\t%-20s\t\t%-20s\t\tPrice\n", "Item Code", "Item Description", "Type");
    for (int i = start; i < stop; i++) {
        printf("%-10s\t", restaurant.item[i].item_code);
        printf("%-20s\t\t", restaurant.item[i].description);
        printf("%-20s\t\t", restaurant.item[i].type);
        printf("$%.2f\n", restaurant.item[i].price);
    }
}

char choose_menu() {
    char choice;
    while (1) {
        printf("a. Single Serving\nb. Package Serving\nc. Group Serving\n\nPick a letter to show its menu: ");
        choice = getchar();
        if (choice != 'a' && choice != 'b' && choice != 'c') {
            printf("Invalid input, try again\n\n");
        }
        else {
            printf("\n\n");
            break;
        }
    }
    return choice;
}

void print_cart() {
    printf("Here are the food that you plan to buy:\n\n");
    printf("%-10s\t%-20s\t\tQTY\t\tPrice\t\tTotal Amount\n", "Item_code", "Item Description");
    for (int i = 0; i < 10; i++) {
        if (restaurant.item[i].quantity > 0) {
            printf("%-10s\t", restaurant.item[i].item_code);
            printf("%-20s\t\t", restaurant.item[i].description);
            printf("%d\t\t", restaurant.item[i].quantity);
            printf("$%.2f\t\t", restaurant.item[i].price);
            printf("$%.2f\n", restaurant.item[i].total_item_amt);
        }
    }
    printf("\n\n");
}

void bill_out(int table_num) {
    float amount_tendered;
    printf("\t\t\tMASARAP-KUMAIN RESTAURANT\n");
    printf("\t\t\t143 MABUSOG ST., LOVE CITY\n\n");
    printf("\t\t\tBILLING STATEMENT\n\n");
    printf("DATE: 06/26/2023");
    printf("\nTABLE NO: %d\n", table_num);

    print_cart();
    restaurant.total_bill = 0;

    for (int i = 0; i < 10; i ++) {
        if (restaurant.item[i].quantity > 0) 
            restaurant.total_bill += restaurant.item[i].total_item_amt;
    }

    if (restaurant.total_bill >= 0 && restaurant.total_bill <= 1000) {
        restaurant.discount = restaurant.total_bill * 0.02;
    } 
    
    else if (restaurant.total_bill >= 1001 && restaurant.total_bill <- 2000)
        restaurant.discount = restaurant.total_bill * 0.03;
    
    else if (restaurant.total_bill > 2000) 
        restaurant.discount  = restaurant.total_bill * 0.05;
    
    restaurant.net_bill = restaurant.total_bill - restaurant.discount;

    printf("\n\n");
    printf("TOTAL BILL: %.2f\n", restaurant.total_bill);
    printf("DISCOUNT: %.2f\n", restaurant.discount);
    printf("NET BILL: %.2f\n\n",  restaurant.net_bill);
    while (1) {
        printf("AMOUNT TENDERED: ");
        if (scanf("%f", &amount_tendered) != 1 || amount_tendered < restaurant.net_bill) {
            clear_input_buffer();
            printf("Invalid input, try again\n\n");
        }
        else {
            break;
        }
    }
    printf("\n\nCHANGE: %.2f", amount_tendered - restaurant.net_bill);
}

void clear_input_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
        // Clear the input buffer
    }
}

