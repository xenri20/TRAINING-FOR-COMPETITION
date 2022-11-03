#include <stdio.h>

int main (){
    long int s, i, first = 1, fibonacci = 1;

    scanf("%d", &s);

    for (i = 3; i<=s; i++){
    fibonacci = fibonacci + s;
    }

    if (s == 1){
        printf("%d", s);
    }
    else {
        printf("%d", fibonacci);
    }
}
