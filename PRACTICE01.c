#include <stdio.h>

int main(){
int Numbers[10] = {1,2,3,4,5,6,7,8,9,10};
int SEven, SOdd, i;

for(i=0; i<=9; i++){
if(Numbers[i]%2 == 0){
    SEven += Numbers[i];
}
}

printf("Sum of EVEN: %d", SEven);

}
