/*
 * File name: solu.cpp
 */

// 这题就找规律

class Solution {
public:
    vector<int> diStringMatch(string S) {
        int head = 0, tail = S.size();
        vector<int> A;
        
        for (auto c : S) {
            if (c == 'I') {
                A.push_back(head++);
            } else {
                A.push_back(tail--);
            }
        }
        A.push_back(head);
        
        return A;
    }
};
