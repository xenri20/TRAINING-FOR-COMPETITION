#include <stdio.h>

int main(){
    FILE *point;
    point = fopen("test.txt", "w");

    char lbn[100];

    printf("Input a sentence for the file: ");
    fgets(lbn, 100, stdin);
    printf("The file test.txt created successfully...!!!");

    fprintf(point, "%s", lbn);
    fclose(point);

    return 0;
}
