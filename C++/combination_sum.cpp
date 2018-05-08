/*
 *can't solve
 *reference from:
 *    https://leetcode.com/problems/combination-sum/discuss/16496/Accepted-16ms-c++-solution-use-backtracking-easy-understand.
 */

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> combination;
        int begin = 0;
        combinationSum(candidates, res, target, combination, 0);
        return res;
    }
private:
    void combinationSum(vector<int>& candidates, vector<vector<int>>& res, int target, vector<int>& combination, int begin) {
        if (!target) {
            res.push_back(combination);
            return;
        }
        for (int i = begin; i != candidates.size() && target >= candidates[i]; i++) {
            combination.push_back(candidates[i]);
            combinationSum(candidates, res, target - candidates[i], combination, i);
            combination.pop_back();
        }
    }
};
