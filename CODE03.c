#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main() {

    float R, X, Y, half, halff, halfff, sum;

    scanf("%f", &R);
    scanf("\n%f", &X);
    scanf(" %f", &Y);

    half = R/2;
    halff = half+(half*0.05);
    halfff = half-(half*0.05);
    sum = X+Y;

    if (halff <= sum && sum >= 0){
        printf("RECALIBRATE");
    }
    else {
        printf("CONTINUE");
    }

    return 0;
}
