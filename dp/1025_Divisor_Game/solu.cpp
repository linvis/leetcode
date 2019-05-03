/*
 * File name: solu.cpp
 */

/*
 * 这道题我理解错了，我理解成了，是不管两人怎么走，Alice一定会赢的意思
 * 但是实际上，字面意思是，只要有一种方案Alice能赢，就可以赢
 * 
 * 所以只需要让Bob每次遇到的N为奇数，Alice就能赢
 * 
 * 我的答案里遍历了所有可能, 找出了能让Alice赢的方案
 */


class Solution {
public:
    bool divisorGame(int N) {
        vector<int> ret(N, 0);
        
        /*
        int tmp = N;    
        int m = 1;
        while (1) {
            for (int j = m; j  < tmp; ) {
                if (tmp % j != 0) {
                    j++;
                    continue;
                }
                tmp = tmp - j;
                if (ret[tmp])
                    break;
                ret[tmp] = 1;
                if (tmp == 2)
                    return false;
                if (tmp == 1)
                    return true;
                j = 1;
            }
            if (m < N) {
                m++;
                tmp = N;
            } else 
                break;
        }
        return true;
    */
        // 1 indicate alice round
        // return sub_divisor(N, ret, 1);
        return N % 2 == 0; 
    }
    bool sub_divisor(int N, vector<int> &ret, int round) {
        if (N == 2) {
            if (round)
                return true;
            else
                return false;
        }
        if (N == 3) {
            if (round)
                return false;
            else
                return true;
        }
        
        for (int i = 1; i < N; i++) {
            if (N % i != 0)
                continue;
            //if (ret[N - i])
             //   continue;
            if (sub_divisor(N - i, ret, !round) == true)
                return true;
            //ret[N - i] = 1;
        }
        
        return false;
    }
};
