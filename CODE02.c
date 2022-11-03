#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main() {

    int L, W, i, a, spaces, b;

    scanf("%d", &L);
    scanf("\n%d", &W);

    for (i = 1; i<=W; i++){
        printf("#");
    }
    printf("\n");
    for (a = 3; a<=L; a++){
        printf("#");
        for (spaces = 3; spaces<=W; spaces++){
            printf(" ");
        }
        printf("#\n");
    }
    for (b = 1; b<=W; b++){
        printf("#");
    }

    return 0;
}
