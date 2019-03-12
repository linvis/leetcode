/*
 * File name: 832_Flipping_an_Image/solu1.cpp
 */

// 这道题这么个意思, 对于[1, 0, 0], 先按中轴旋转，变成[0, 0, 1],
// 然后bit反转[1, 1, 0]

// 常规解法就是遍历两边，第一遍先旋转，第二遍在反转
// 实际上，是完全可以遍历一次，
// 这个解法 runtime beats 100%, memory beats 13%
// 我推测大概是用了lambda，和直接操作vector导致的
class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        auto glambda = [](auto a) {return (a == 1 ? 0 : 1);};
        
        for (auto &a : A) {
            int size = a.size();
            int i = 0;
            for (; i < size - 1 - i; i++) {
                a[i] = glambda(a[i]);
                //a[i] = a[i] == 1 ? 0 : 1;
                a[size - 1 - i] = glambda(a[size - 1 - i]);
                swap(a[i], a[size - 1 - i]);
            }
            if (size % 2 != 0)
                a[i] = glambda(a[i]);
        }
        
        return A;
    }
};
