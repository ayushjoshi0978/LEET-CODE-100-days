#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* intersect(int* nums1, int nums1Size,
               int* nums2, int nums2Size,
               int* returnSize) {

    int freq[1001] = {0};

    // Count frequency of nums1
    for (int i = 0; i < nums1Size; i++) {
        freq[nums1[i]]++;
    }

    // Allocate result array
    int maxSize = nums1Size < nums2Size ? nums1Size : nums2Size;
    int* result = (int*)malloc(sizeof(int) * maxSize);
    *returnSize = 0;

    // Find intersection
    for (int i = 0; i < nums2Size; i++) {
        if (freq[nums2[i]] > 0) {
            result[*returnSize] = nums2[i];
            (*returnSize)++;
            freq[nums2[i]]--;
        }
    }

    return result;
}
