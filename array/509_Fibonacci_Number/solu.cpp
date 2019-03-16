/*
 * File name: solu.cpp
 */

/*
 * 这题就是斐波那契数列，常规的做法是 return fib(N - 1) + fib[N - 2];
 * 但是你会发现，在算fib[N - 1]的时候，是算过一遍fib[N - 2]的，因此实际上fib[N - 2]是算了两遍的
 * 所以使用动态规划的思想, 先算fib[N - 2]， 然后返回{fib[N - 2], fib[N - 3], fib[N - 4]}
 * 然后就可以求出fib[N - 1]了
 */

class Solution {
public:
    int fib(int N) {

        return _fib(N)[0];
    }
    
    vector<int> _fib(int N) {
        
        if (N == 2)
            return {1, 1, 0};
        if (N == 1)
            return {1, 0, 0};
        if (N == 0)
            return {0, 0, 0};
        
        vector<int> a = _fib(N - 2);
        
        int b = a[0] + a[1];
        
        return {a[0] + b, b, a[0]};
    }
};

/*
 * 我这个解法是用了递归的DP，一般形式的DP(循环的形式)应该是:
 * ref:https://leetcode.com/problems/fibonacci-number/discuss/218301/C%2B%2B-3-Solutions-Explained-Recursive-or-Iterative-with-DP-or-Imperative
 */
int fib(int N) {
    if(N < 2)
        return N;
    int memo[N+1];
    memo[0] = 0;
    memo[1] = 1;
    for(int i=2; i<=N; i++)
        memo[i] = memo[i-1] + memo[i-2];
    return memo[N];
}

