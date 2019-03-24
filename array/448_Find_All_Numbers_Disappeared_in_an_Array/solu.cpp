/*
 * File name: solu.cpp
 */

/*
 * 这题关键词是A[A[i]]
 * 这里有个更快的方法，令A[A[i]]为-A[A[i]]就好了，这样是遍历1遍就可以了
 * 我下面的做法，有局部重复遍历的可能
 */

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        for (int i = 0; i < nums.size();) {
            if (nums[i] != -1) {
                int tmp = nums[i];
                if (nums[tmp - 1] == -1) {
                    i++;
                    continue;
                }
                swap(nums[nums[i] - 1], nums[i]); 
                nums[tmp - 1] = -1;
            } else {
                i++;
            }
        }
        
        vector<int> B;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != -1)
                B.push_back(i + 1);
        }
        
        return B;
    }
};
