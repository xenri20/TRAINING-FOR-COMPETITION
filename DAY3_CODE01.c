#include <stdio.h>

int main (){
    int i, large, set1, set2, set3, set4, count = 0;
    int sizes[9];

    for (i = 0; i<=4; i++){
    scanf("%d", &sizes[i]);
    }

    scanf("%d", &large);

    set1 = sizes[1]+sizes[1+2];

    while (set1 <= large){
        count++;
        set1++;
    }

    printf("%d", count);

}
