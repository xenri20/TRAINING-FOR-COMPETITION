#include <stdio.h>

int main(){
int SIZE, i;

printf("Input the number of elements to store in the array: ");
scanf("%d", &SIZE);
printf("Input %d number of elements in the array:", SIZE);

float Number[SIZE];
SIZE = SIZE - 1;
for(i=0; i<=SIZE; i++){
printf("\nElement %d: ", i);
scanf("%f", &Number[i]);
}

printf("The floating-point values stored into the array are: \n");
for(i=0; i<=SIZE; i++){
    printf("%.2f\t", Number[i]);
}

printf("\nThe floating-point values stored into the array in reverse are: \n");
for(i=0; i<=SIZE; SIZE--){
    printf("%.2f\t", Number[SIZE]);
}

return 0;
}
