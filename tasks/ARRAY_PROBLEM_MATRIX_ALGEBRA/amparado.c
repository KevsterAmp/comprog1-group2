#include <stdio.h>

void compute(int arraya[3], int arrayb[3][3], int arrayc[3]);
void display(int x[3], int y[3][3], int z[3]);

int main(){
    int arraya[3], arrayb[3][3];

    for (int i = 0; i < 3; i++) {
        printf("Input arraya[%d]: ", i);
        scanf("%d", &arraya[i]);
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("Input arrayb[%d][%d]: ", i, j);
            scanf("%d", &arrayb[i][j]);
        }
    }

    int arrayc[3];
    compute(arraya, arrayb, arrayc);
    display(arraya, arrayb, arrayc);
}

void compute(int arraya[3], int arrayb[3][3], int arrayc[3]){
    for (int i = 0; i < 3; i++) {
        arrayc[i] = 0;
        for (int j = 0; j < 3; j++) {
            arrayc[i] += arraya[j] * arrayb[j][i];
        }
    }
}

void display(int x[3], int y[3][3], int z[3]) {
    printf("arraya = [%d, %d, %d]\n", x[0], x[1], x[2]);
    printf("arrayb =\n ");
    for (int i = 0; i < 3; i++) {
        printf("[%d, %d, %d]\n", y[i][0], y[i][1], y[i][2]);
    }
    printf("arrayc = [%d, %d, %d]\n", z[0], z[1], z[2]);
}
