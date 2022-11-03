#include <stdio.h>

int main(){
FILE *points;
x:
printf("Input the file name to be opened: ");
char lbn[100];
scanf("%s", lbn);

points = fopen(lbn, "r");
char out[100];

if (points == NULL){
    printf("Wrong file! Please input again.\n");
    goto x;
}

fgets(out, 100, points);
printf("The content of the file %s is: \n", lbn);
printf("%s", out);
fclose(points);

return 0;

}
