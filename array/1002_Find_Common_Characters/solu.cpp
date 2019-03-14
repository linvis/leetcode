/*
 * File name: solu.cpp
 */

// 我的做法，我试图把第一组字符标记为[111111...]
// 然后对于后续的每个字符，查下跟第一组里的字符，是否有重复，有的话++变化->[112111...]
// 最后只有查下这个count表里，出现次数等于总次数的就好了

// 我这里的问题是，三层loop，太费时了

// 标准的做法是，预制一个包含26个字母的数组，用作base
// 然后遍历每一个字符串，每一个字符串都有自己在26个字母中的分布tmp
// 比较min(base, tmp), 这样就求了交集(出现重复无所谓的)
// base[c - 'a']，直接定位c的位置

// 这里一个很明显的思想是，cache，根据当前值和cache比较，刷新cache

class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        vector<int> count(A[0].size(), 1);
        
        for (int i = 1; i < A.size(); i++) {
            for (int j = 0; j < A[i].size(); j++) {
                for (int m = 0; m < A[0].size(); m++) {
                    if (A[i][j] == A[0][m] && count[m] == i) {
                        count[m]++;
                        break;
                    }
                }
            }
        }
        
        vector<string> B;
        for (int i = 0; i < count.size(); i++) {
            if (count[i] == A.size()) {
                char s = A[0][i];
                B.push_back(string(1, s));
            }
        }
        
        return B;
    }
};

// ref:https://leetcode.com/problems/find-common-characters/discuss/247573/C%2B%2B-O(n)-or-O(1)-two-vectors
vector<string> commonChars(vector<string>& A) {
    vector<int> cnt(26, INT_MAX);
    vector<string> res;
    for (auto s : A) {
        vector<int> cnt1(26, 0);
        for (auto c : s) ++cnt1[c - 'a'];
        for (auto i = 0; i < 26; ++i) cnt[i] = min(cnt[i], cnt1[i]);
    }
    for (auto i = 0; i < 26; ++i)
        for (auto j = 0; j < cnt[i]; ++j) res.push_back(string(1, i + 'a'));
    return res;
}
