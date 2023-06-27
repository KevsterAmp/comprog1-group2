#include <stdio.h>
#include <conio.h>

struct resto {
    struct items {
        char type[10];
        char item_code[10];
        float price;
        char description[20];
        int quantity;
        float total_item_amt;
    };
    struct items item[10]; 
    float total_bill;
    float discount;
    float net_bill;
    float change;
};
struct resto restaurant;

int main(void) {
    r.item[0].type = "Single Serving";
    restaurant.item[0].item_code = "JR010";
    restaurant.item[0].description= "Java Rice";
    restaurant.item[0].price = 50;

    restaurant.item[1].type = "Single Serving";
    restaurant.item[1].item_code = "PR030";
    restaurant.item[1].description= "Pork Steak";
    restaurant.item[1].price = 120;

    restaurant.item[0].type = "Single Serving";
    restaurant.item[0].item_code = "VE070";
    restaurant.item[0].description= "Chopsuey";
    restaurant.item[0].price = 100;

    restaurant.item[0].type = "Single Serving";
    restaurant.item[0].item_code = "B210";
    restaurant.item[0].description= "Ice Tea";
    restaurant.item[0].price = 35;

    restaurant.item[0].type = "Package Serving";
    restaurant.item[0].item_code = "Pack1";
    restaurant.item[0].description= "Package1";
    restaurant.item[0].price = 320;

    restaurant.item[0].type = "Package Serving";
    restaurant.item[0].item_code = "Pack2";
    restaurant.item[0].description= "Package2";
    restaurant.item[0].price = 420;

    restaurant.item[0].type = "Package Serving";
    restaurant.item[0].item_code = "Pack3";
    restaurant.item[0].description= "Package3";
    restaurant.item[0].price = 500;

    restaurant.item[0].type = "Group Serving";
    restaurant.item[0].item_code = "FG1";
    restaurant.item[0].description= "Family Group Serving";
    restaurant.item[0].price = 550;

    restaurant.item[0].type = "Group Serving";
    restaurant.item[0].item_code = "BG";
    restaurant.item[0].description= "Barkada Group Serving";
    restaurant.item[0].price = 650;

    restaurant.item[0].type = "Group Serving";
    restaurant.item[0].item_code = "FG2";
    restaurant.item[0].description= "Fiesta Group Serving";
    restaurant.item[0].price = 750;
}