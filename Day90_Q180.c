/*Given an integer array nums and an integer k, split nums into k non-empty subarrays such that the largest sum of any subarray is minimized.

Return the minimized largest sum of the split.

A subarray is a contiguous part of the array.

 

Example 1:

Input: nums = [7,2,5,10,8], k = 2
Output: 18
Explanation: There are four ways to split nums into two subarrays.
The best way is to split it into [7,2,5] and [10,8], where the largest sum among the two subarrays is only 18.
Example 2:

Input: nums = [1,2,3,4,5], k = 2
Output: 9
Explanation: There are four ways to split nums into two subarrays.
The best way is to split it into [1,2,3] and [4,5], where the largest sum among the two subarrays is only 9.
 

Constraints:

1 <= nums.length <= 1000
0 <= nums[i] <= 106
1 <= k <= min(50, nums.length)*/

#include <stdio.h>

int isPossible(int* nums, int n, int k, long long mid) {
    int count = 1;
    long long sum = 0;

    for (int i = 0; i < n; i++) {
        if (nums[i] > mid) return 0;

        if (sum + nums[i] <= mid) {
            sum += nums[i];
        } else {
            count++;
            sum = nums[i];
            if (count > k) return 0;
        }
    }
    return 1;
}

int splitArray(int* nums, int numsSize, int k) {
    long long low = 0, high = 0;

    for (int i = 0; i < numsSize; i++) {
        if (nums[i] > low) low = nums[i];
        high += nums[i];
    }

    long long ans = high;

    while (low <= high) {
        long long mid = low + (high - low) / 2;

        if (isPossible(nums, numsSize, k, mid)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return (int)ans;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    int nums[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    printf("%d\n", splitArray(nums, n, k));
    return 0;
}