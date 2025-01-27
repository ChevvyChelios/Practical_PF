#include<stdio.h>
int main(){
    int num = -1234, rem, new=0;
    int sign = (num<0) ? -1 : 1;
    num *= sign;
    while(num > 0){
        rem = num%10;
        new = 10*new + rem;
        num /= 10;
    }
    printf("%d \n", new*sign);
    return 0;
}