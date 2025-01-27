#include<stdio.h>
int main(){
    int a=20, b=50;
    
    a = a^b;
    b = a^b;
    a = a^b;

    // a = a+b;
    // b = a-b;
    // a = a-b;

    // a = a*b;
    // b = a/b;
    // a = a/b;

    printf("a = %d\nb = %d\n", a,b);
    return 0;
}