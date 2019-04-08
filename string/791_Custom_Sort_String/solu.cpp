/*
 * File name: solu.cpp
 */

/*
 * 这题的思路，首先遍历T，把T扔到一个hashtab里，
 * 这样就获取了每个字符出现的次数
 * 
 * 然后遍历S，查找S里的每个字符是否在T中出现，
 * 如果出现，就所有的字符都附加到r上, 然后从map里删除该字符
 * 
 * 最后在map里遍历一下，看看有哪些元素剩下，剩下的都是S中没出现的
 *
 * 这样的时间复杂度是: O(M + N) (len(S) = M, len(T) = N)
 */


class Solution {
public:
    string customSortString(string S, string T) {
        unordered_map<char, int> map;
        string r;
        
        for (auto t : T) {
            if (map.count(t) == 0) {
                map[t] = 1;
            } else {
                map[t]++;
            }
        }
        
        for (auto s : S) {
            if (map.count(s) == 1) {
                string tmp(map[s], s);
                r.append(tmp);
                map.erase(s);
            }
        }
        
        for (auto it : map) {
            string tmp(it.second, it.first);
            r.append(tmp);
        }
        
        return r;
    }
};
