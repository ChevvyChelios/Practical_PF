#include<stdio.h>
int sumOfDigits(int num){
    int sum = 0;
    while (num > 0){
        sum += num%10;
        num /= 10;
    }
    return sum;
}
int digitalRoot(int num){
    while (num >= 10){
        num = sumOfDigits(num);
    }
    return num;
}
int main(){
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    int result = digitalRoot(num);
    printf("The sum of the digits until a single digit is obtained: %d\n", result);
    return 0;
}