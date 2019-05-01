/*
 * My solution, works but time limited.
 * My fault is I do many repeat calculation, and I want get F(N),
 * then I try to get F(N - 1), that is wrong, correct way is get F(1), then 
 * get F(2), until get F(n).
 */
class Solution {
public:
    int uniquePaths(int m, int n) {
        if (m == 1) {
            return 1;
        }
        if (n == 1) {
            return 1;
        }

        return uniquePaths(m - 1, n) + uniquePaths(m, n - 1);
    }
};


/*
 * Correct solution
 */
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int> > path(m, vector<int> (n, 1));
        for (int i = 1; i < m; i++)
            for (int j = 1; j < n; j++)
                path[i][j] = path[i - 1][j] + path[i][j - 1];
        return path[m - 1][n - 1];
    }
};
