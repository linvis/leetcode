/*
 * File name: solu.cpp
 */

/*
 * 这题思路没问题，有问题的是代码写的太糟糕了
 * 由于对string不熟悉，导致很多基本操作api清楚，
 * 所以各种if/else嵌套
 */

class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_map<string, int> map;
        int before_at = 0;
        int after_plus = 0;
        
        for (auto email : emails) {
            string s;
            before_at = 1;
            after_plus = 0;
            for (int i = 0; i < email.size(); i++) {
                if (before_at) {
                    if (email[i] == '.')
                        continue;
                    else if (email[i] == '+') {
                        after_plus = 1;
                        continue;
                    } else if (email[i] == '@') {
                        before_at = 0;
                        after_plus = 0;
                        s.push_back(email[i]);
                    } else {
                        if (!after_plus)
                            s.push_back(email[i]);
                    }
                } else {
                    s.push_back(email[i]);
                }
            }
            if (map.count(s) == 0)
                map.insert(pair<string,int>(s, 1) );
        }
        
        return map.size();
    }
};
