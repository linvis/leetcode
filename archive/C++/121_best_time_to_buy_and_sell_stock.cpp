/*
 * DP:
 * Sn+1 = max((An+1 - min(A1...An)), max_profit)
 */

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int buy = 0;
        
        if (prices.size() <=0)
            return 0;
        
        return getDiff(prices, prices.size(), &buy);
        
    }
    int getDiff(vector<int>& prices, int size, int *buy) {
        int sell = prices.at(size - 1);
        int diff = 0;
        
        if (size <= 1) {
            *buy = prices.at(0);
            return 0;
        } else {
            diff = getDiff(prices, size - 1, buy);
            if (sell < *buy) {
                *buy = sell;
                return diff; 
            }
            
            if ((sell - *buy) > diff)
                return (sell - *buy);
            else
                return diff;
        }
    }
};
