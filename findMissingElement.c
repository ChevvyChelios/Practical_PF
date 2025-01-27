#include<stdio.h>
int findMissingNumber(int arr[], int n)
{
    int total = (n*(n+1)) / 2;
    int sum = 0;
    for (int i=0; i<n-1; i++){
        sum += arr[i];
    }
    return total-sum;
}

int main(){
    int n;

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n - 1];
    printf("Enter %d integers (from 1 to %d): ", n - 1, n);
    for (int i = 0; i < n - 1; i++)
    {
        scanf("%d", &arr[i]);
    }
    int missingNumber = findMissingNumber(arr, n);

    printf("The missing number is: %d\n", missingNumber);
    return 0;
}