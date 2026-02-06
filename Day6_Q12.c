/*Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Note that you must do this in-place without making a copy of the array.

 

Example 1:

Input: nums = [0,1,0,3,12]
Output: [1,3,12,0,0]
Example 2:

Input: nums = [0]
Output: [0]
 

Constraints:

1 <= nums.length <= 104
-231 <= nums[i] <= 231 - 1*/

#include <stdio.h>
#define N 100
int main() {
    int n, nums[N];
    
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    
    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }
    
    int non_zero_index = 0;
    
    for (int i = 0; i < n; i++) {
        if (nums[i] != 0) {
            nums[non_zero_index++] = nums[i];
        }
    }
    
    while (non_zero_index < n) {
        nums[non_zero_index++] = 0;
    }
    
    printf("Array after moving zeros to the end: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", nums[i]);
    }
    
    printf("\n");
    return 0;
}