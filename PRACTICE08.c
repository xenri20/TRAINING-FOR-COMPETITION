#include <stdio.h>

int main(){
FILE *points;
int wrd = 0, let = 0;

printf("Input the file name to be opened: ");
char lbn[100];
scanf("%s", lbn);

points = fopen(lbn, "r");
int out = fgetc(points);

printf("The content of the file %s are:\n", lbn);

while(out != EOF){
    putchar(out);
    let++;
    if (out == ' ' || out == '\n'){
        let--;
        wrd++;
    }
    out = fgetc(points);
}

printf("\nThe number of words in the file %s are: %d", lbn, wrd+1);
printf("\nThe number of characters in the file %s are: %d", lbn, let);
fclose(points);
return 0;
}
