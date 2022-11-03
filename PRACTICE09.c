#include <stdio.h>

int main(){
FILE *app;
int line, i;

printf("Input the file name to be opened: ");
char flname[100], perline[50];
scanf("%s", flname);

app = fopen(flname, "a");

printf("Input the number of lines to be written: ");
scanf("%d", &line);
printf("The lines are:\n");
for(i=0; i<=line; i++){
    gets(perline);
    fprintf(app, "\n%s", perline);
}

fclose(app);
app = fopen (flname, "r");
printf("The content of the file %s is :\n",flname);
char fin = fgetc(app);
while (fin != EOF){
    printf("%c", fin);
    fin = fgetc(app);
}
fclose (app);
return 0;
}
