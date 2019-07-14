/*
 * File name: solu.cpp
 */

/*
 * 这题是这样的，传动带运行物品，每个物品重量w，分几次运，给定次数，求传送带最大可承载重量
 * weight一定在max(weights)和sum(weights)之间
 * 二分查找
 * 复杂度 NlogN
 */

class Solution {
public:
    int shipWithinDays(vector<int>& weights, int D) {
        int min_weight = *max_element(weights.begin(), weights.end());
        long max_weight = accumulate(weights.begin(), weights.end(), 0);
        int cur_weight = 0, valid_weight = max_weight;
        
        while (min_weight < max_weight) {
            cur_weight = (min_weight + max_weight) / 2;
            if (is_weight_valid(weights, D, cur_weight)) {
                valid_weight = cur_weight;
                max_weight = cur_weight;
            } else {
                if (cur_weight == min_weight)
                    break;
                min_weight = cur_weight;
            }
        }

        return valid_weight;

    }
    
    bool is_weight_valid(vector<int> weights, int D, int max_weight) {
        long rest = accumulate(weights.begin(), weights.end(), 0);
        int cuts = 0;
        int d = D - 1;
        for (int i = 0; i < weights.size();) {
            if (cuts + weights[i] <= max_weight) {
                if (weights.size() - i - 1 <= d)
                    return true;
                cuts += weights[i];
                rest -= weights[i];
                i++;
                continue; 
            } else {
                if (rest > (long)max_weight * d) {
                    return false;
                } else {
                    cuts = 0; 
                    rest -= weights[i];
                    if (--d < 0) {
                        return false;
                    }
                }
            }
        }
        
        if (d == 0)
            return true;
        else
            return false;
    }
};
