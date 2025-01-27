#include<stdio.h>
struct Result
{
    int maxCount;
    int maxBegin;
};

struct Result count(int arr[], int n)
{
    int maxBegin=0, maxCount=1, ssBegin=0, count=1, k=1;
    while (k < n){
        if (arr[k] == arr[k-1]){
            count++;
            if (count > maxCount){
                maxCount = count;
                maxBegin = ssBegin;
            }
        }
        else {
            ssBegin = k;    count = 1;
        }
        k++;
    }
    struct Result res = {maxCount, maxBegin};
    return res;
}
int main(){
    int arr[] = {3,1,2,2,2,2,3,4,1,5,5,5,6,1,2};
    int n = sizeof(arr) / sizeof(arr[0]);
    struct Result result = count(arr, n);
    printf("Max Count: %d, Start Index: %d\n", result.maxCount, result.maxBegin);

    // for (int i=result.maxBegin; i<=result.maxCount; i++)
    //     printf("%d ", arr[i]);
    printf("\n");
    return 0;
}