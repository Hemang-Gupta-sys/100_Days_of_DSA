/*Problem: Given an array of integers, find two elements whose sum is closest to zero.

Input:
- First line: integer n
- Second line: n space-separated integers

Output:
- Print the pair of elements whose sum is closest to zero

Example:
Input:
5
1 60 -10 70 -80

Output:
-10 1

Explanation: Among all possible pairs, the sum of -10 and 1 is -9, which is the closest to zero compared to other pairs.*/

#include <stdio.h>
#include <stdlib.h>
#define N 100
int main() {
    int n, arr[N];
    
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    
    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    int min_sum = 2147483647; 
    int pair1 = 0, pair2 = 0;
    
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            int sum = arr[i] + arr[j];
            if (abs(sum) < abs(min_sum)) {
                min_sum = sum;
                pair1 = arr[i];
                pair2 = arr[j];
            }
        }
    }
    
    printf("The pair of elements whose sum is closest to zero is: %d %d\n", pair1, pair2);
    
    return 0;
}