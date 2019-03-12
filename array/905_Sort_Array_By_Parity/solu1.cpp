/*
 * File name: solu1.cpp
 */

// 这道题就是，偶数在前，奇数在后

// 第一种解法，暴力插入，遇到偶数，插在vector头部，奇数尾部
// 问题就是效率低
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        vector<int> B;
        
        for (auto a : A) {
            if (a % 2 == 0) {
                B.insert(B.begin(), a);
            } else {
                B.push_back(a);
            }
        }
        
        return B;
    }
};

// 第二种解法，用数组操作，不用vector，这里考虑到vector的insert到head，
// 可能是每次都会发生移位操作
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        int size = A.size();
        int B[size];
        int head = 0, tail = size - 1;
        
        for (auto a : A) {
            if (a % 2 == 0) {
                B[head++] = a;
            } else {
                B[tail--] = a;
            }
        }
        
        vector<int> varr(B, B + size);
        
        return varr;
    }
};
