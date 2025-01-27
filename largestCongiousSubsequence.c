

// -----------     BUJA NAI     -------------------

#include <stdio.h>

int longestIncreasingSubsequence(int arr[], int n)
{
    int lis[n]; // Array to store the longest increasing subsequence lengths
    int maxLength = 0;

    // Initialize LIS values for all indexes
    for (int i = 0; i < n; i++)
    {
        lis[i] = 1; // Each element is an increasing subsequence of length 1
    }

    // Compute the LIS values
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (arr[i] > arr[j] && lis[i] < lis[j] + 1)
            {
                lis[i] = lis[j] + 1; // Update LIS length
            }
        }
    }

    // Find the maximum length from the LIS array
    for (int i = 0; i < n; i++)
    {
        if (maxLength < lis[i])
        {
            maxLength = lis[i];
        }
    }

    return maxLength;
}

int main()
{
    int n;

    printf("Enter size of array: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int length = longestIncreasingSubsequence(arr, n);

    printf("Length of the longest increasing subsequence is: %d\n", length);

    return 0;
}