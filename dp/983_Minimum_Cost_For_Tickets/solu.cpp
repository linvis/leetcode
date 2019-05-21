/*
 * File name: solu.cpp
 */

对于days中的每个元素来说，它可能属于三个套餐，分别是 +1，+7，+30
即，求这三个套餐中sum最小
F(n) = min(F(n-1) + costs[0], F(n - 7) + cost[1], F(n - 30) + cost[2])
这里有一个额外要注意的是， F(0) = 0, (所以sum的长度要+1)
比如days[1,4], costs[7,2]
应该输出2，而不是7

class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> sum(days.size() + 1, 0);
        
        for (int i = 0; i < days.size(); i++) {
            int j = i + 1;
            sum[j] = sum[j - 1] + costs[0];
            
            int index = get_index(days, i, 7);
            sum[j] = min(sum[j], sum[index + 1] + costs[1]);
            
            index = get_index(days, i, 30);
            sum[j] = min(sum[j], sum[index + 1] + costs[2]);
        }
        
        return sum.back();
    }
    
    int get_index(vector<int> &days, int pos, int duration) {
            int i = pos;
            int diff = days[i] - duration;
        
            while (i >= 0 && days[i] > diff) {
               i--;
            }
            return i;
    }
};
