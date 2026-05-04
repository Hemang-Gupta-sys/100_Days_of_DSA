/*Given an integer array nums and an integer k, return the kth largest element in the array.

Note that it is the kth largest element in the sorted order, not the kth distinct element.

Can you solve it without sorting?

 

Example 1:

Input: nums = [3,2,1,5,6,4], k = 2
Output: 5
Example 2:

Input: nums = [3,2,3,1,2,4,5,5,6], k = 4
Output: 4
 

Constraints:

1 <= k <= nums.length <= 105
-104 <= nums[i] <= 104*/

#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int nums[], int low, int high) {
    int pivot = nums[high];
    int i = low;
    for (int j = low; j < high; j++) {
        if (nums[j] <= pivot) {
            swap(&nums[i], &nums[j]);
            i++;
        }
    }
    swap(&nums[i], &nums[high]);
    return i;
}

int quickSelect(int nums[], int low, int high, int k) {
    if (low <= high) {
        int pi = partition(nums, low, high);
        if (pi == k) return nums[pi];
        else if (pi < k) return quickSelect(nums, pi + 1, high, k);
        else return quickSelect(nums, low, pi - 1, k);
    }
    return -1;
}

int findKthLargest(int* nums, int numsSize, int k) {
    return quickSelect(nums, 0, numsSize - 1, numsSize - k);
}

int main() {
    int nums[] = {3,2,1,5,6,4};
    int n = sizeof(nums) / sizeof(nums[0]);
    int k = 2;
    printf("%d\n", findKthLargest(nums, n, k));
    return 0;
}