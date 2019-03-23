/*
 * File name: solu.cpp
 */

/*
 * 这道题的解法：
 * 首先，找最大值，找到以后，先把它翻转到A[0], 然后翻转到A[n]
 * 然后递归的算，就可以了
 * 这里我看了很多解法是直接用sort先排好序，然后就可以直接取最大值了，
 * 这里我没有用sort，而是手工找的最大值，另外pancakeReverse这个函数，
 * 是因为我刚开始不知道reverse函数...
 */

class Solution {
public:
    vector<int> pancakeSort(vector<int>& A) {
        vector<int> B;
       
        pancakeStep(A, A.size(), B);
        
        return B;
    }
    
    void pancakeStep(vector<int>& A, int len, vector<int>& B) {
        if (len <= 1)
            return;
        
        int maxNumIdx = findMaxNumIdx(A, len);
        
        if (maxNumIdx == 0) {
            // pancakeReverse(A, len - 1);
            reverse(A.begin(), A.begin() + len - 1);
            B.push_back(len);
            pancakeStep(A, --len, B);
        } else if (maxNumIdx == len - 1) {
            // do nothing
            pancakeStep(A, --len, B);
        } else {
            // pancakeReverse(A, maxNumIdx);
            reverse(A.begin(), A.begin() + maxNumIdx);
            B.push_back(maxNumIdx + 1);
            pancakeStep(A, len, B);
        }
    }
    
    void pancakeReverse(vector<int>& A, int idx) {
        for (int i = 0; i <= idx / 2; i++) {
            swap(A[idx - i], A[i]);
        }
    }
    
    int findMaxNumIdx(vector<int>& A, int len) {
        int maxNum = 0;
        int maxNumIdx = 0;
        for (int i = 0; i < len; i++) {
            if (A[i] > maxNum) {
                maxNum = A[i];
                maxNumIdx = i;
            }
        }
        return maxNumIdx;
    }
};
