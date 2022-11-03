#include <stdio.h>
#include <string.h>
#define X 1024

int main(){
FILE *OP;
FILE *REP;
int num, Rline = 0, Nline = 1;

char line[X], change[X], name[X], tempname[X];
printf("Input the file name to be opened: ");
scanf("%s", name);

strcpy(tempname, "Z");
strcat(tempname, name);

fflush(stdin);

printf("Input the content of the new line: ");
fgets(change, X, stdin);

printf("Input the line number you want to replace: ");
scanf("%d", &num);

OP = fopen(name, "r");
REP = fopen(tempname, "w");

while(Rline == 0){
    fgets(line, X, OP);
    if (feof(OP)){
        Rline = 1;
    }
    else if(Nline == num){
        fputs(change, REP);
    }
    else{
        fputs(line, REP);
    }
    Nline++;
}

fclose(OP);
fclose(REP);
remove(name);
rename(tempname, name);

printf("Replacement did successfully!!");
return 0;
}
