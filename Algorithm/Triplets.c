#include <stdio.h>
#include <stdlib.h>

// Function to compare two integers for sorting
int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

// Function to find all unique triplets that sum up to zero
int **threeSum(int *nums, int numsSize, int *returnSize, int **returnColumnSizes) {
    qsort(nums, numsSize, sizeof(int), compare); // Sort the array

    int **result = NULL;
    *returnSize = 0;
    *returnColumnSizes = NULL;

    for (int i = 0; i < numsSize - 2; i++) {
        // Skip duplicate values
        if (i > 0 && nums[i] == nums[i - 1]) {
            continue;
        }
        
        int left = i + 1;
        int right = numsSize - 1;

        while (left < right) {
            int sum = nums[i] + nums[left] + nums[right];

            if (sum == 0) {
                (*returnSize)++;
                result = (int **)realloc(result, sizeof(int *) * (*returnSize));
                result[*returnSize - 1] = (int *)malloc(3 * sizeof(int));
                result[*returnSize - 1][0] = nums[i];
                result[*returnSize - 1][1] = nums[left];
                result[*returnSize - 1][2] = nums[right];

                // Skip duplicate values
                while (left < right && nums[left] == nums[left + 1]) {
                    left++;
                }
                while (left < right && nums[right] == nums[right - 1]) {
                    right--;
                }

                left++;
                right--;
            } else if (sum < 0) {
                left++;
            } else {
                right--;
            }
        }
    }

    *returnColumnSizes = (int *)malloc(*returnSize * sizeof(int));
    for (int i = 0; i < *returnSize; i++) {
        (*returnColumnSizes)[i] = 3;
    }

    return result;
}

int main() {
    int nums1[] = {0, 0, 0, -1, 1};
    int numsSize1 = sizeof(nums1) / sizeof(nums1[0]);
    int returnSize1;
    int *returnColumnSizes1;
    int **result1 = threeSum(nums1, numsSize1, &returnSize1, &returnColumnSizes1);

    printf("Example 1:\n");
    for (int i = 0; i < returnSize1; i++) {
        printf("[%d, %d, %d]\n", result1[i][0], result1[i][1], result1[i][2]);
    }

    
    return 0;
}
