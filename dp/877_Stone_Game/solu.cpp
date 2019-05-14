/*
 * File name: solu.cpp
 */

/*
 * 这题是个陷阱，仔细分析下，对于[a,b,c,d]四元来说
 * 如果 a+c > b+d，那么，我先选a，不管另一个人怎么选，我一定能选到c, win
 * 如果 b+d > a+c, 那么，先选d, 一定可以选到b
 * 
 * 这样，不管怎么走，一定会赢
 */

class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        return true;
    }
};


/*
 * 原始的计算解法
 */
class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int head = 0, tail = piles.size() - 1;
        int sum = 0;
        int sum_a = 0;
        
        for (auto p : piles)
            sum += p;
        
        while (head <= tail) {
            if (piles[head] + piles[tail - 1] > (piles[tail] + piles[head + 1])) {
                sum_a += piles[head++];
                tail--;
            } else {
                sum_a += piles[tail--];
                head++;
            }
        }
        
        return sum_a > (sum - sum_a);
    }
};
