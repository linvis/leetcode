/*
 * File name: solu.cpp
 */

class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        int B[A.size()];
        int odd = 0, even = 1;
        
        for (auto a : A) {
            if (a % 2 == 0) {
                B[odd] = a;
                odd += 2;
            } else {
                B[even] = a;
                even += 2;
            }
        }
        
        return vector<int> (B, B + A.size());
    }
};
