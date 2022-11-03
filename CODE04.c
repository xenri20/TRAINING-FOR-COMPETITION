#include <stdio.h>

int main() {

    char * C, C1 = "Admin Room", C2 = "Top Deck", C3 = "Management", C4 = "Lobby", C5 = "Recreation Room", C6 = "Comfort Room", C7 = "Canteen";
    int A, B, PASS_1, PASS_2;

    scanf("%d", &A);
    scanf(" %d", &B);
    scanf("\n%[^\n]%*c", C);

    if (A<=17 || A>=18){
        if (B<=2){
        PASS_1 = 1;
        }
        else {
        PASS_1 = 0;
        }
    }
    else {
        PASS_1 = 0;
    }

    switch (PASS_1){
    case 0:
        if (C == C1 || C == C2 || C == C3){
        printf("NOT ALLOWED");
    }
    break;
    case 1:
        if (C == C4 || C == C5 || C == C6 || C == C7){
        if (PASS_1 == 1){
            printf("ALLOWED");
        }
        else {
            printf("NOT ALLOWED");
        }
    }
    break;
    default:
        printf("UNKNOWN");
    }

    return 0;
}
