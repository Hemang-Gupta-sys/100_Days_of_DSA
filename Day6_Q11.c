/*Problem: Given a sorted array of n integers, remove duplicates in-place. Print only unique elements in order.

Input:
- First line: integer n
- Second line: n space-separated integers (sorted array)

Output:
- Print unique elements only, space-separated

Example:
Input:
6
1 1 2 2 3 3

Output:
1 2 3

Explanation: Keep first occurrence of each element: 1, 2, 3*/

#include <stdio.h>
#define N 100
int main() {
    int n, arr[N];
    
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    
    printf("Enter the sorted elements of the array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    printf("Unique elements in order: ");
    for (int i = 0; i < n; i++) {
        if (i == 0 || arr[i] != arr[i - 1]) {
            printf("%d ", arr[i]);
        }
    }
    
    printf("\n");
    return 0;
}