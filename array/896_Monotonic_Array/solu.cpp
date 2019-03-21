/*
 * File name: solu.cpp
 */

/*
 * 这题开始做的时候，犯了一个错误，为了找direction，
 * 直接比的 A[0] 和A[1]
 * 这是错误的，首先A.size()可能为1,
 * 其次可能A[0] == A[1]
 * 动态的推断direction
 */

class Solution {
public:
    bool isMonotonic(vector<int>& A) {
        int dir = 0;
        
        for (int i = 0; i < A.size() - 1; i++) {
            if (dir == 0) {
                if (A[i] == A[i + 1])
                    continue;
                if (A[i] < A[i + 1])
                    dir = 1;
                else
                    dir = -1;
            } else if (dir == 1) {
                if (A[i] > A[i + 1])
                    return false;
            } else {
                if (A[i] < A[i + 1])
                    return false;
            }
        }
        
        return true;
    }
};
