#include <stdio.h>

int main(){
int SIZE, i, b, sum;

printf("Input the size of the square matrix(less than 5): ");
scanf("%d", &SIZE);

int FIRST_MAT[SIZE][SIZE], SECOND_MAT[SIZE][SIZE];

printf("Input elements in the first matrix:\n");
for (i=0; i!=SIZE; i++){
    for(b=0; b!=SIZE; b++){
        printf("Element [%d][%d]: ", i, b);
        scanf("%d", &FIRST_MAT[i][b]);
    }
}

printf("Input elements in the second matrix:\n");
for (i=0; i!=SIZE; i++){
    for(b=0; b!=SIZE; b++){
        printf("Element [%d][%d]: ", i, b);
        scanf("%d", &SECOND_MAT[i][b]);
    }
}

printf("The First matrix is:\n");
for (i=0; i!=SIZE; i++){
    for(b=0; b!=SIZE; b++){
        printf("%d\t", FIRST_MAT[i][b]);
    }
    printf("\n");
}

printf("The Second matrix is:\n");
for (i=0; i!=SIZE; i++){
    for(b=0; b!=SIZE; b++){
        printf("%d\t", SECOND_MAT[i][b]);
    }
     printf("\n");
}

printf("The Addition of two matrix is:\n");
for (i=0; i!=SIZE; i++){
    for(b=0; b!=SIZE; b++){
        sum = FIRST_MAT[i][b] + SECOND_MAT[i][b];
        printf("%d\t", sum);
    }
     printf("\n");
}

return 0;
}
