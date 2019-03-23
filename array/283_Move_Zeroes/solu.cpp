/*
 * File name: solu.cpp
 */

/*
 * 我这个解法有些迂腐，其实可以这么做，两个指针，一个指向0，
 * 另一个指针遍历，遇到非0元素，直接覆盖另一个指针指向的0元素，
 * 这样就可以实现把所有的非0元素移到前面了
 */

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int size = nums.size();
        int count = 0;
        for (int i = 0; i < size;) {
            if (count++ >= size)
                break;
            if (nums[i] == 0) {
                nums.erase(nums.begin() + i);
                nums.push_back(0);
            } else
                i++;
        }
    }
};

ref:https://leetcode.com/problems/move-zeroes/solution/
void moveZeroes(vector<int>& nums) {
    int lastNonZeroFoundAt = 0;
    // If the current element is not 0, then we need to
    // append it just in front of last non 0 element we found. 
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] != 0) {
            nums[lastNonZeroFoundAt++] = nums[i];
        }
    }
 	// After we have finished processing new elements,
 	// all the non-zero elements are already at beginning of array.
 	// We just need to fill remaining array with 0's.
    for (int i = lastNonZeroFoundAt; i < nums.size(); i++) {
        nums[i] = 0;
    }
}
