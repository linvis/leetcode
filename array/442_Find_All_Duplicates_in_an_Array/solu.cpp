/*
 * File name: solu.cpp
 */

/*
 * 这题的思路，首先这道题有一个非常大的限制，是不允许使用额外的空间，
 * 这意味着类似hash-map这种数据结构是不允许的
 * 因此，只能从nums本身入手，修改nums标记哪个元素是否出现
 * 此外，观察此题，会发现一个重要的细节1 ≤ a[i] ≤ n (n = size of array),
 * 这以为着我完全可以通过 a[a[i]]这种形式的访问
 * 所以遍历数组，标记a[a[i]]为0，表示这个元素已经出现过了，继续遍历，
 * 当发现a[a[i]]为0，就意味着元素重复出现了
 * 
 * 提交测试130ms，有点意外，看了116ms的算法，类似的实现
 */

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> B;
        
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0)
                continue;
            int tmp = nums[nums[i] - 1];
            if (tmp == 0)
                B.push_back(nums[i]);
            else {
                nums[nums[i] - 1] = 0;
                if (nums[i] - 1 > i)
                    nums.push_back(tmp);
            }
        }
        return B;
    }
};
