/*
 * File name: solu.cpp
 */

/*
 * 从N算到1，我这个思路是对的，但是代码写的太啰嗦，
 * 很明显，是因为我对C++熟悉度不够，很多api不清楚
 * 时间复杂度是: O(N*(S + logN))
 * logN是 toBinary
 * S 是find
 */

class Solution {
public:
    bool queryString(string S, int N) {
        vector<int> search(N, 0);
    
        for (int i = N - 1; i >= 0 ; i--) {
            if (search[i] == 0) {
                string num = toBinary(i + 1);
                if (find(S, num) == false)
                    return false;
                else {
                    int tmp = i + 1;
                    while (tmp / 2) {
                        tmp /= 2;
                        search[tmp - 1] = 1;
                    }
                }
            }
        }
        
        return true;
    }
    
    bool find(string S, string n) {
        for (int i = 0; i < S.size(); i++) {
            if (S.compare(i, n.size(), n) == 0)
                return true;
        }
        return false;
    }
    
    string toBinary(int N) {
        string num;
        while (N) {
            if (N % 2) {
                num.push_back('1');
            } else {
                num.push_back('0');
            }
            N /= 2;
        }
        reverse(num.begin(), num.end()); 
        return num;
    }
};

// ref: https://leetcode.com/problems/binary-string-with-substrings-representing-1-to-n/discuss/260882/C%2B%2B-O(S-log-N)-vs.-O(N-*-(S-%2B-log-N))
bool queryString(string S, int N) {
  while (N > 0) {
    auto s = bitset<32>(N--).to_string();
    if (S.find(s.substr(s.find("1"))) == string::npos) return false;
  }
  return true;
}
