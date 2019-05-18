/*
 * File name: solu.cpp
 */

/*
 * 假设在第n个台阶，可以从n-2处，走2步到达，
 * 也可以从n-1处，走1步到达
 * 所以总的方案： F(n) = F(n-1) + F(n-2)
 */

class Solution {
public:
    int climbStairs(int n) {
        int s1 = 1, s2 = 1;
        int sum = 0;
        
        for (int i = 1; i < n; i++) {
            sum = s1 + s2;
            
            s1 = s2;
            s2 = sum;
        }
        
        return max(sum, s2);
    }
};
