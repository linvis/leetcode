/*
 * File name: solu.cpp
 */

/*
 * 这题比较典型的动态规划
 * 这里我的思路是 n = 2^i + m, m是已经算过的, 2^i里含有1个1
 * 
 * 然后实际上，可以更简单, n  = m << 2, 对于n,m, 两个含1的数量是一样的
 * 只要额外处理下奇偶就可以了
 */

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> ret;
        int tmp = 1;
        
        for (int n = 0; n <= num; n++) {
            if (n <= 1) {
                ret.push_back(n);
            } else {
               if (n > tmp && n < (tmp << 1)) {
                   ret.push_back(1 + ret[n - tmp]); 
               } else {
                   tmp = tmp << 1;
                   ret.push_back(1);
               }
            }
        }
        
        return ret;
    }
};
