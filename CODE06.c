#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main() {

    int s, i, a, spaces = 1, b, c;
     b = s-1;
    scanf("%d", &s);

    for (i = 1; i<=s; i++){
        c = 1;
        while (c <= b){
            c++;
            printf(" ");
        }
        while (c<=s){
            printf("#");
        }
        printf("\n");
    }

    return 0;
}
