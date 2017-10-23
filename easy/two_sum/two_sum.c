/*
 *brute force version
 */

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target) {
    int* result = malloc(2*sizeof(int));
    if (result == NULL)
        return "Error";
    int i, j;
    for (i = 0; i < numsSize; i++)
        for (j = i + 1; j < numsSize; j++)
            if ( nums[i] + nums[j] == target) {
                result[0] = i;
                result[1] = j;
                return result;
            }
    free(result);
    return "No conform";
                
}
