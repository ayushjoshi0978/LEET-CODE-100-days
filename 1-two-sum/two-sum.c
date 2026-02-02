#include <stdio.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloc'ed, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    // Allocate space for result (two indices)
    int* result = (int*)malloc(2 * sizeof(int));
    *returnSize = 2;

    // Brute force approach (O(n^2))
    for (int i = 0; i < numsSize; i++) {
        for (int j = i + 1; j < numsSize; j++) {
            if (nums[i] + nums[j] == target) {
                result[0] = i;
                result[1] = j;
                return result;
            }
        }
    }

    // If no solution found (though problem guarantees one)
    *returnSize = 0;
    return NULL;
}