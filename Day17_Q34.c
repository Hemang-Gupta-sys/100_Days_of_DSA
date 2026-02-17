/*Given an integer array nums, find the subarray with the largest sum, and return its sum.

 

Example 1:

Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: The subarray [4,-1,2,1] has the largest sum 6.
Example 2:

Input: nums = [1]
Output: 1
Explanation: The subarray [1] has the largest sum 1.
Example 3:

Input: nums = [5,4,-1,7,8]
Output: 23
Explanation: The subarray [5,4,-1,7,8] has the largest sum 23.
 

Constraints:

1 <= nums.length <= 105
-104 <= nums[i] <= 104*/

#include <stdio.h>
#define N 100
int maxSubArray(int* nums, int numsSize) {
    int max_sum = nums[0];
    int current_sum = nums[0];

    for (int i = 1; i < numsSize; i++) {
        current_sum = (current_sum > 0) ? current_sum + nums[i] : nums[i];
        if (current_sum > max_sum) {
            max_sum = current_sum;
        }
    }

    return max_sum;   
}

int main() {
    int n, nums[N];
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    int result = maxSubArray(nums, n);
    printf("The largest sum of a subarray is: %d\n", result);
    
    return 0;
}