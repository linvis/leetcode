/*
 * File name: solu.cpp
 */

/*
 * 这题没做出来，时间超了，我的做法O(n2)了
 * 实际上，刚开始我想到了状态转移方程
 * P x N的形式，A[x] = PN
 * 但是我忘记了N怎么求，我在想随着P右移，N应该左移，所以N里用到了除法，
 * 然后放弃了这个思路，我忘记了我可以从尾部反向求解，就变成了乘法运算
 */

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int fromBegin = 1;
        int fromEnd = 1;
        int n = nums.size();
        vector<int> res(n, 1);
        
        for (int i = 0; i < n; i++) {
            res[i] *= fromBegin;
            fromBegin *= nums[i];
            res[n - i - 1] *= fromEnd;
            fromEnd *= nums[n - i - 1];
        }
        return res;

    }
};
