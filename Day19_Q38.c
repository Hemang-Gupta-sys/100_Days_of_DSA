/*Given a circular integer array nums of length n, return the maximum possible sum of a non-empty subarray of nums.

A circular array means the end of the array connects to the beginning of the array. Formally, the next element of nums[i] is nums[(i + 1) % n] and the previous element of nums[i] is nums[(i - 1 + n) % n].

A subarray may only include each element of the fixed buffer nums at most once. Formally, for a subarray nums[i], nums[i + 1], ..., nums[j], there does not exist i <= k1, k2 <= j with k1 % n == k2 % n.

 

Example 1:

Input: nums = [1,-2,3,-2]
Output: 3
Explanation: Subarray [3] has maximum sum 3.
Example 2:

Input: nums = [5,-3,5]
Output: 10
Explanation: Subarray [5,5] has maximum sum 5 + 5 = 10.
Example 3:

Input: nums = [-3,-2,-3]
Output: -2
Explanation: Subarray [-2] has maximum sum -2.
 

Constraints:

n == nums.length
1 <= n <= 3 * 104
-3 * 104 <= nums[i] <= 3 * 104*/

#include <stdio.h>
#include <stdlib.h>
#define N 100
int maxSubarraySumCircular(int* nums, int numsSize) {
    int max_sum = nums[0];
    int current_max = nums[0];
    int min_sum = nums[0];
    int current_min = nums[0];
    int total_sum = nums[0];

    for (int i = 1; i < numsSize; i++) {
        total_sum += nums[i];
        
        current_max = (current_max > 0) ? current_max + nums[i] : nums[i];
        max_sum = (max_sum > current_max) ? max_sum : current_max;
        
        current_min = (current_min < 0) ? current_min + nums[i] : nums[i];
        min_sum = (min_sum < current_min) ? min_sum : current_min;
    }

    return (max_sum > 0) ? ((total_sum - min_sum > max_sum) ? total_sum - min_sum : max_sum) : max_sum;   
}

int main() {
    int n, nums[N];
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    int result = maxSubarraySumCircular(nums, n);
    
    printf("The maximum possible sum of a non-empty subarray is: %d\n", result);
    
    return 0;
}