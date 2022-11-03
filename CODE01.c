#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    int i, j;
    float k, a;

    scanf("%d", &i);
    scanf("\n%d", &j);
    scanf("\n%f", &k);

    a = i*(1.00+k);

    if (j>a){
        printf("Additional Flat Damage");
    }
    else{
        printf("Critical Strike Chance");
    }
    if (a==i || j==a){
        printf("Equal");
    }

    return 0;
}
