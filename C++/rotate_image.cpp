/*
 *Time: O(n2)
 *Space: O(1)
 *assume it as a maze, have N loop, like 回, rotate every loop
 */

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int i = 0, j = 0;
        int len_hori = matrix.size();
        int len_vert = matrix[0].size();

        for ( ; i <= (len_hori-1) / 2; i++) {
            for (j = i ; j <= (len_vert -2 -i); j++) {
                rotateCircle(matrix, i, j, len_hori);
            }
        }
    }
private:
    void rotateCircle(vector<vector<int>>& matrix, int m, int n, int len) {
        int swap = matrix[m][n];
        int tmp_m = m;
        for (int i = 0; i < 4; i++) {
            int tmp = matrix[n][len - 1 - m];
            matrix[n][len - 1 - m] = swap;
            swap = tmp;
            tmp_m = m;
            m = n;
            n = len - 1 - tmp_m;
        }    
    }
};
