/*Koko loves to eat bananas. There are n piles of bananas, the ith pile has piles[i] bananas. The guards have gone and will come back in h hours.

Koko can decide her bananas-per-hour eating speed of k. Each hour, she chooses some pile of bananas and eats k bananas from that pile. If the pile has less than k bananas, she eats all of them instead and will not eat any more bananas during this hour.

Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.

Return the minimum integer k such that she can eat all the bananas within h hours.

 

Example 1:

Input: piles = [3,6,7,11], h = 8
Output: 4
Example 2:

Input: piles = [30,11,23,4,20], h = 5
Output: 30
Example 3:

Input: piles = [30,11,23,4,20], h = 6
Output: 23
 

Constraints:

1 <= piles.length <= 104
piles.length <= h <= 109
1 <= piles[i] <= 109*/

#include <stdio.h>

long long hoursNeeded(int* piles, int size, int k) {
    long long hours = 0;
    for (int i = 0; i < size; i++) {
        hours += (piles[i] + k - 1) / k;
    }
    return hours;
}

int minEatingSpeed(int* piles, int pilesSize, int h) {
    int max = 0;
    for (int i = 0; i < pilesSize; i++) {
        if (piles[i] > max)
            max = piles[i];
    }

    int low = 1, high = max, ans = max;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (hoursNeeded(piles, pilesSize, mid) <= h) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return ans;
}

int main() {
    int n;
    scanf("%d", &n);

    int piles[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &piles[i]);

    int h;
    scanf("%d", &h);

    int result = minEatingSpeed(piles, n, h);
    printf("%d\n", result);

    return 0;
}