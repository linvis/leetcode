/*
 * File name: solu.cpp
 */

// common solution

class Solution {
public:
    int countSubstrings(string s) {
        vector<string> pa;
        
        for (int i = 0; i < s.size(); i++) {
            pa.push_back(string(1, s[i]));
            for (int j = 1; i - j >= 0 && i + j < s.size(); j++) {
                if (s[i - j] == s[i + j]) {
                    pa.push_back(s.substr(i - j, 2 * j + 1));
                } else
                    break;
            }
            
            for (int j = 1; i - j >= 0 && i + j - 1 < s.size(); j++) {
                if (s[i - j] == s[i + j - 1]) {
                    pa.push_back(s.substr(i - j, 2 * j));
                } else
                    break;
            }
        }
        
        return pa.size();
    }
};
