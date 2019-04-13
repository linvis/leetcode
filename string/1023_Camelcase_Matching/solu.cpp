/*
 * File name: solu.cpp
 */

// 常规解法，这里用了个递归，实际上用循环更简练一些

class Solution {
public:
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        vector<bool> ret;
        
        for (auto q : queries) {
            ret.push_back(match(q, pattern));
        }
        
        return ret;
    }
    
    bool match(string query, string pattern) {
        int j = 0;
        for (int i = 0; i < query.size(); ) {
            if (!pattern[j] || query[i] != pattern[j]){
                if (query[i] >= 'a' && query[i] <= 'z') {
                    i++;
                    continue;
                } else {
                    return false;
                }
            } else if (query[i] == pattern[j]) {
                return match(query.substr(i + 1), pattern.substr(j + 1));
            }
        }
        
        if (j < pattern.size())
            return false;
        
        return true;
    }
};
