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
