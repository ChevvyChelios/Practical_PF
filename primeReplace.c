
#include <stdio.h>
#include <stdbool.h>

bool is_prime(int num) {
    if (num <= 1) return false;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return false;
    }
    return true;
}
int next_prime(int num) {
    num++; // Start checking from the next number
    while (!is_prime(num)) {
        num++;
    }
    return num;
}
void replace_evens_with_primes(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        if (arr[i] % 2 == 0) { // Check if the number is even
            arr[i] = next_prime(arr[i]); // Replace with the next prime
        }
    }
}
int main() {
    int A[] = {2, 5, 24, 15, 9, 8, 3};
    int size = sizeof(A) / sizeof(A[0]);

    printf("Original array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");

    replace_evens_with_primes(A, size);

    printf("Modified array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");

    return 0;
}