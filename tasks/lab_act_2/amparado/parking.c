#include <stdio.h>
#include <string.h>

#define MAX_ENTRIES 10
#define CAR_RATE 25
#define BUS_RATE 50
#define TRUCK_RATE 75

struct parking_hours {
    int hour_in;
    int hour_out;
    int total_hours;
    float fee;
};

struct cust_veh_info {
    char cust_name[20];
    char cust_address[30];
    char veh_plate_num[10];
    char veh_make[10];
    char veh_color[10];
    char veh_type[10];
    struct parking_hours parking_hours;
};

struct cust_veh_info info[MAX_ENTRIES];

void getInput(int index);
void computeFees(int index);
void printInfo(int index);

int main(void) {
    int x;
    for (int i = 0; i < MAX_ENTRIES; i++) {
        getInput(i);

        printf("\nDo you want to continue? (y/n): ");
        char choice;
        scanf(" %c", &choice);

        if (choice == 'n') {
            x = i;
            break;
        }
    }

    computeFees(x);
    printInfo(x);

    return 0;
}

void getInput(int index) {
    char temp[10];
    int time_temp1, time_temp2;
    
    printf("Enter customer name: ");
    scanf(" %[^\n]", info[index].cust_name);

    printf("Enter customer address: ");
    scanf(" %[^\n]", info[index].cust_address);

    printf("Enter vehicle plate number: ");
    scanf(" %s", info[index].veh_plate_num);

    printf("Enter vehicle make: ");
    scanf(" %s", info[index].veh_make);

    printf("Enter vehicle color: ");
    scanf(" %s", info[index].veh_color);

    while (1) {
        printf("Enter vehicle type (car, bus, truck): ");
        scanf(" %s", temp);
        if (strcmp(temp, "car") != 0) {
            if (strcmp(temp, "bus") != 0) {
                if (strcmp(temp, "truck") != 0) {
                    printf("invalid input, try again\n");
                    continue;
                }}}
        break;
    } 

    strcpy(info[index].veh_type, temp);

    do {
        printf("Enter hour in: ");
        scanf(" %d", &time_temp1);

        if (time_temp1 > 2400 || (time_temp1 % 100) > 60)
            printf("Invalid input, try again\n");
    } while(time_temp1 > 2400 || (time_temp1 % 100) > 60);

    do {
        printf("Enter hour out: ");
        scanf(" %d", &time_temp2);

        if (time_temp2 > 2400 || (time_temp2 % 100) > 60)
            printf("Invalid input, try again\n");
    } while(time_temp2 > 2400 || (time_temp2 % 100) > 60);

    info[index].parking_hours.hour_in = time_temp1;
    info[index].parking_hours.hour_out = time_temp2;

}

void computeFees(int index) {
    for (int i = 0; i <= index; i++) {
        info[i].parking_hours.total_hours = (info[i].parking_hours.hour_out - info[i].parking_hours.hour_in) / 100;

        if (strcmp(info[i].veh_type, "car") == 0) {
            info[i].parking_hours.fee = info[i].parking_hours.total_hours * 25;
        } else if (strcmp(info[i].veh_type, "bus") == 0) {
            info[i].parking_hours.fee = info[i].parking_hours.total_hours * 50;
        } else if (strcmp(info[i].veh_type, "truck") == 0) {
            info[i].parking_hours.fee = info[i].parking_hours.total_hours * 75;
        } 
    }
}

void printInfo(int index) {
    for(int i = 0; i <= index; i++) {
        printf("\nCustomer name: %s", info[i].cust_name);
        printf("\nCustomer address: %s", info[i].cust_address);
        printf("\n\nVehicle Plate Number\tVehicle Make\tVehicle Color\tVehicle Type\n");
        printf("%s\t\t\t%s\t\t%s\t\t%s\n", info[i].veh_plate_num, info[i].veh_make, info[i].veh_color, info[i].veh_type);
        printf("\nHours spent in parking area: %d\n", info[i].parking_hours.total_hours);
        printf("Parking fee: %.2f\n", info[i].parking_hours.fee);
    }
}
