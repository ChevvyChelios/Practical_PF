#include <stdio.h>
#include <math.h>

int swapDigit(int num)
{

    int lastDigit = num % 10;
    int digitCount = log10(num);

    int firstDigit = num / pow(10, digitCount);

    int res = lastDigit * pow(10, digitCount);
    res = res + num % (int)pow(10, digitCount);
    res -= lastDigit;
    res += firstDigit;

    return res;
}

int main()
{
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);

    int res = swapDigit(num);
    printf("New number: %d\n", res);
    return 0;
}