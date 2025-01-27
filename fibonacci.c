#include<stdio.h>
int main(){
    int n, next;
    int n1 = 0, n2 = 1;
    printf("Enter the size of the series: ");
    scanf("%d", &n);
    printf("\nFibonacci series: ");
    for (int i=0; i<n; i++){
        if (i<=1)
            next = i;
        else {
            next = n1 + n2;
            n1 = n2;
            n2 = next;
        }
        printf("%d ", next);
    }
    printf("\n");
    return 0;
}