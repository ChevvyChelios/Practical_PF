#include<stdio.h>
void print(int n){
    if (n > 100)
        return;
    printf("%d ", n);
    print(n+1);
}
int main(){
    print(1);
    return 0;
}