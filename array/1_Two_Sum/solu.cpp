/*
 * File name: solu.cpp
 */
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;
        vector<int> ret;
        
        for (int i = 0; i < nums.size(); i++) {
           if (map.count(target - nums[i])) {
               ret.push_back(map[target - nums[i]]);
               ret.push_back(i);
               break;
           } else {
               map[nums[i]]=i;
           }
        }
        return ret;
    }
};
