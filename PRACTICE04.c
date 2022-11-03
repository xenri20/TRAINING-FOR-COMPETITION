#include <stdio.h>

int main(){
int i, b;
int MATRIX[3][4];

printf("Input elements in the matrix:\n");

for (i=0; i!=3; i++){
    for(b=0; b!=4; b++){
        printf("Element [%d][%d]: ", i, b);
        scanf("%d", &MATRIX[i][b]);
    }
}

printf("The matrix is:\n");
for (i=0; i!=3; i++){
    for(b=0; b!=4; b++){
        printf("%d\t", MATRIX[i][b]);
    }
     printf("\n");
}
return 0;
}
