#include <stdio.h>

#define MAX_STOCK 100

struct shoe {
    int Nstock;
    int style_num;
    int numpairs_size[12];
    float price;
};

typedef struct shoe Shoe;

void newRecord(FILE* file, int* total_records) {
    int flag = 0;
    Shoe shoe;

    while (1) {
        printf("Enter the stock number: ");
        if (scanf("%d", &shoe.Nstock) != 1 || shoe.Nstock < 1 || shoe.Nstock > MAX_STOCK) {
            printf("Invalid input for stock number. Please try again.\n");
            while (getchar() != '\n') {
            }
            return;
        }

        printf("Enter the style number: ");
        if (scanf("%d", &shoe.style_num) != 1 || shoe.style_num < 0 || shoe.style_num > 50 ) {
            printf("Invalid input for style number. Please try again.\n");
            while (getchar() != '\n') {
            }
            return;
        }

        fseek(file, 0, SEEK_SET);
        Shoe temp;
        while (fread(&temp, sizeof(Shoe), 1, file) == 1) {
                if ((temp.Nstock == shoe.Nstock) && (temp.style_num == shoe.style_num)) {
                    printf("Stock number and style number already exists. Please try again.\n\n\n");
                    flag = 1;
                    break;
                } 
            }

        if (flag == 0)
            break;
    }
    
    printf("Enter the shoe price: ");
    if (scanf("%f", &shoe.price) != 1 || shoe.price < 0) {
        printf("Invalid input for shoe price. Please try again.\n");
        while (getchar() != '\n') {

        }
        return;
    }

    printf("Enter the number of pairs according to shoe size:\n");
    for (int size = 3; size <= 12; size++) {
        int index = size - 3;
        printf("Size %d: ", size);
        if (scanf("%d", &shoe.numpairs_size[index]) != 1 || shoe.numpairs_size[index] < 0) {
            printf("Invalid input for size %d. Please try again.\n", size);
            while (getchar() != '\n') {
            }
            return;
        }
    }
    
    fseek(file, (*total_records) * sizeof(Shoe), SEEK_SET);
    fwrite(&shoe, sizeof(Shoe), 1, file);

    (*total_records)++;

}

void changePrice(FILE* file, int total_records) {
    int stock_number;
    float new_price;

    printf("Enter stock number to change the price: ");
    if (scanf("%d", &stock_number) != 1) {
        printf("Invalid input for stock number. Please try again.\n");
        while (getchar() != '\n') {
        }
        return;
    }

    fseek(file, (stock_number - 1) * sizeof(Shoe) + sizeof(int), SEEK_SET);
    fread(&new_price, sizeof(float), 1, file);

    printf("Enter new price: ");
    if (scanf("%f", &new_price) != 1) {
        printf("Invalid input for new price. Please try again.\n");
        while (getchar() != '\n') {
        }
        return;
    }

    fseek(file, (stock_number - 1) * sizeof(Shoe) + sizeof(int), SEEK_SET);
    fwrite(&new_price, sizeof(float), 1, file);

    printf("Price for stock number %d has been updated.\n", stock_number);
}

void displayRecords(FILE* file, int total_records) {
    Shoe shoe;

    printf("Stock\tStyle\tPrice\t");

    for (int size = 3; size <= 12; size++) {
        printf("Size %d\t", size);
    }

    printf("\n--------------------------------------------------------------------------------------------------\n");

    fseek(file, 0, SEEK_SET);

    for (int i = 0; i < total_records; i++) {
        fseek(file, i * sizeof(Shoe), SEEK_SET);
        fread(&shoe, sizeof(Shoe), 1, file);
        printf("%d\t%d\t%.2f\t", shoe.Nstock, shoe.style_num, shoe.price);

        for (int j = 0; j < 10; j++) {
            printf("%d\t", shoe.numpairs_size[j]);
        }

        printf("\n");
    }

    printf("----------------------------------------------------------------------------------------------------\n");
}

void clearRecords(FILE* file) {
    fclose(file);
    file = fopen("shoe_inventory.txt", "w");
    fclose(file);
    printf("File cleared successfully.\n");
}

int main() {
    FILE* file;
    int choice, total_records = 0;

    file = fopen("shoe_inventory.txt", "r+");

    if (file == NULL) {
        file = fopen("shoe_inventory.txt", "w+");
    } else {
        Shoe shoe;
        while (fread(&shoe, sizeof(Shoe), 1, file) == 1) {
            total_records++;
        }
    }

    do {
        printf("\nInventory Management System\n");
        printf("1. Enter new record\n");
        printf("2. Change the price of a stock number\n");
        printf("3. Display records\n");
        printf("4. Clear Records\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid choice. Please try again.\n");
            while (getchar() != '\n') {
                // Clear input buffer
            }
            continue;
        }

        switch (choice) {
            case 1:
                newRecord(file, &total_records);
                fseek(file, 0, SEEK_SET); // Reset file pointer to the beginning
                break;
            case 2:
                changePrice(file, total_records);
                break;
            case 3:
                displayRecords(file, total_records);
                break;
            case 4:
                clearRecords(file);
                total_records = 0; // Reset the total_records counter
                break;
            case 5:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 5);

    fclose(file);

    return 0;
}
