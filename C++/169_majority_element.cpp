
/*
 * Use Hash-Map, but too slow
 */
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        std::map<int, int> mp;
        int max_count = 0, max_n = 0;
        
        for (int n : nums) {
            if(mp.count(n)) {
                mp[n] = mp[n] + 1;
            } else {
                mp[n] = 1;
            }
        }
        
        for (auto it = mp.begin(); it != mp.end(); it++) {
            if (it->second > max_count) {
                max_count = it->second;
                max_n = it->first;
            }
        }
        
        return max_n;
    }
};
