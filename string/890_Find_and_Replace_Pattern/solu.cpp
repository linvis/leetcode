/*
 * File name: solu.cpp
 */

/*
 * 这题的思路，是把造一个模板，把其他字符全转成这个模板
 * 我这里，如果字符第一次出现，按照'abc..'赋值，
 * 然后扔到map里，下次如果遇到重复的字符，从map里取出模板的字符，进行替换
 * 比如： xyyx的形式，最终被替换成 abba的形式
 */

class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        string patt = trans(pattern);
        vector<string> res;
        for (auto s : words) {
            if (trans(s) == patt) {
                res.push_back(s);
            }
        }
        return res;
    }
    
    string trans(string pattern) {
        string s;
        unordered_map<char, int> map;
        int tmp = 0;
        for (int i = 0; i < pattern.size(); i++) {
            if (map.count(pattern[i]) == 0) {
                map[pattern[i]] = i;
                s.push_back('a' + tmp++);
            } else {
                s.push_back(s[map[pattern[i]]]);
            }
        }
        return s;
    }
};
