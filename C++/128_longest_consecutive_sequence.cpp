
/*
 * My Solution, unsuccessfully.
 * I try to use a big array to tag all data, if the number appears, tag 1, if not ,tag 0
 * but here is one problem, if the number is too large, it will fail to malloc enough space.
 */

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        int max_n = 0, min_n = 0;
        for (int n : nums) {
            max_n = max(n, max_n);
            min_n = min(n, min_n);
        }
        
        vector<int> tag(max_n + 1 - min_n, 0);
        
        for (int n : nums) {
            int m = n - min_n; 
            tag[m] = 1; 
        }
        
        int len = 0, max_len = 0;
        for (int t : tag) {
            if (t == 1) {
                len++;
            } else {
                max_len = max(len, max_len);
                len = 0;
            }
        }
        
        return max(max_len, len);
    }
};


A reference:
https://leetcode.com/problems/longest-consecutive-sequence/discuss/41088/Possibly-shortest-cpp-solution-only-6-lines.

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int r = 0;
        unordered_map<int, int> m;
        
        for (int i : nums) {
           if (m[i])
               continue;
            m[i] = m[i - 1] + m[i + 1] + 1;
            m[i - m[i - 1]] = m[i];
            m[i + m[i + 1]] = m[i];
            r = max(r, m[i]);
        }
        return r;
    }
};
