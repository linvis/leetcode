/*
 * File name: solu.cpp
 */

// 这道题思路很简单，先平方，在排序
// 然后是耗时比较多，内存吃的也很多，因为用了vector
//
// 这道题更好的做法，官方也给了，因为A已经事先排好序了，
// 所以可以先找到 0，然后向两头出发，merge合并

class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        
        for (auto &a : A)
            a = a * a;
        
        sort(A.begin(), A.end(), [](int x, int y){return (x < y);});
        return A;
    }
};
