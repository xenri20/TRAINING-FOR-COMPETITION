#include<stdio.h>
#include<string.h>

int main()
{
    int rom[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    char months[12][10] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    int day[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    for(int i = 0; i<=11; i++)
    {
        printf("%d\t\t", rom[i]);
    }
    printf("\n");

    for (int i = 0; i < 12; i++)
    {
        if((strlen(months[i]))<=7){
            printf("%s\t\t", months[i]);
        }
        else
        {
            printf("%s\t", months[i]);
        }

    }
}