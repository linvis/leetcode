/*
 * File name: solu.cpp
 */

/*
 * 这题没想出来
 * 看一下答案，解释一下
 * 首先对于A[N][N]
 * 它可移动的范围是 C[2N][2N]
 * 然后，对于A中的任意一个1，它都有可能移动到另一个1上, 只是移动的步骤会不一样
 * 这里，我们A中的任何一个1，都计算一下它移动到B中的任意一个1的 "路径",
 * 放到C中，路径相同就累加，最后找到这个最大值
 */

// java
class Solution {
    public int largestOverlap(int[][] A, int[][] B) {
        int N = A.length;
        int[][] count = new int[2*N+1][2*N+1];
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < N; ++j)
                if (A[i][j] == 1)
                    for (int i2 = 0; i2 < N; ++i2)
                        for (int j2 = 0; j2 < N; ++j2)
                            if (B[i2][j2] == 1)
                                count[i-i2 +N][j-j2 +N] += 1;

        int ans = 0;
        for (int[] row: count)
            for (int v: row)
                ans = Math.max(ans, v);
        return ans;
    }
}
