/*Problem: Given an array of integers, count the frequency of each distinct element and print the result.

Input:
- First line: integer n (size of array)
- Second line: n integers

Output:
- Print each element followed by its frequency in the format element:count

Example:
Input:
5
1 2 2 3 1

Output:
1:2 2:2 3:1*/

#include <stdio.h>
#define N 100
int main() {
    int n, arr[N], frequency[N] = {0};
    
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    
    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    for (int i = 0; i < n; i++) {
        frequency[arr[i]]++;
    }
    
    printf("Element:Frequency\n");
    for (int i = 0; i < N; i++) {
        if (frequency[i] > 0) {
            printf("%d:%d ", i, frequency[i]);
        }
    }
    printf("\n");
    
    return 0;
}