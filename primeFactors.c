#include<stdio.h>
void primeFactors(int num){
    while (num%2 == 0){
        printf("2 ");
        num /= 2;
    }
    for (int i=3; i*i <= num; i+=2){
        while(num%i == 0){
            printf("%d ", i);
            num /= i;
        }
    }
    if (num > 2){
        printf("%d \n", num);
    }
}
int main(){
    int number;

    printf("Enter a number to find its prime factors: ");
    scanf("%d", &number);

    printf("Prime factors of %d are: ", number);
    primeFactors(number);
    printf("\n");
    return 0;
}