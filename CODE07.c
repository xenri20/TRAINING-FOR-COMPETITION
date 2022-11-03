#include <stdio.h>
#include <string.h>
int checkPalindromeStr(char str[]);


int checkPalindromeStr(char str[])
{
    int i, j, len;
    len = 0;
    while(str[len]!='\0'){
        len++;
    }
    for(i=0, j=(len-1); i<=(len-1); i++, j--)
    {
        if(str[i] != str[j]){
            return 1;
        }
    }
    return 0;
}

int main()
{
    char word[100];
    char ext[] = {"EXIT"};
    int chk, horse = 0;
    int indicator=1;//true


    while(horse == 0){
        printf("Enter any String (word): ");
        scanf("%s", word);

        if(strcmp(word, ext)==0){
        return 0;
        }
        chk = checkPalindromeStr(word);
        if(chk==1){
        printf("\nIt's not a Palindrome String\n\n");
        }
        else {
        printf("\nIt's a Palindrome String\n\n");
        }
    }
}



