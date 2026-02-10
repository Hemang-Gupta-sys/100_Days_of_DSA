/*Given two integer arrays nums1 and nums2, return an array of their intersection. Each element in the result must appear as many times as it shows in both arrays and you may return the result in any order.

 

Example 1:

Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2,2]
Example 2:

Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [4,9]
Explanation: [9,4] is also accepted.
 

Constraints:

1 <= nums1.length, nums2.length <= 1000
0 <= nums1[i], nums2[i] <= 1000*/

#include <stdio.h>
#define N 100
int main() {
    int n1, n2, nums1[N], nums2[N], intersection[N], k = 0;
    
    printf("Enter the number of elements in the first array: ");
    scanf("%d", &n1);
    
    printf("Enter the elements of the first array: ");
    for (int i = 0; i < n1; i++) {
        scanf("%d", &nums1[i]);
    }
    
    printf("Enter the number of elements in the second array: ");
    scanf("%d", &n2);
    
    printf("Enter the elements of the second array: ");
    for (int i = 0; i < n2; i++) {
        scanf("%d", &nums2[i]);
    }
    
    for (int i = 0; i < n1; i++) {
        for (int j = 0; j < n2; j++) {
            if (nums1[i] == nums2[j]) {
                intersection[k++] = nums1[i];
                nums2[j] = -1; 
                break;
            }
        }
    }
    
    printf("Intersection of the two arrays: ");
    for (int i = 0; i < k; i++) {
        printf("%d ", intersection[i]);
    }
    printf("\n");
    
    return 0;
}