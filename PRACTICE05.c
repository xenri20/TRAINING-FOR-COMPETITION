#include <stdio.h>

int main(){
    FILE *point;
    point = fopen("ECast.txt", "w");

    fprintf(point, "pukinangina\nTangina\nputangina");

    fclose(point);

    return 0;
}
