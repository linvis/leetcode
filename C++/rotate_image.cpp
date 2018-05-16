/*
 *Time: O(n2)
 *Space: O(1)
 *assume it as a maze, have N loop, like 回, rotate every loop
 */

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int i = 0, j = 0;
        int len = matrix.size();

        for ( ; i <= (len-1) / 2; i++) {
            for (j = i ; j <= (len -2 -i); j++) {
                rotateCircle(matrix, i, j, len);
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

/*
 *A reference:https://leetcode.com/problems/rotate-image/discuss/19002/4ms-few-lines-C++-code-Rotate-Image-90-degree-for-O(1)-space
 *Smart rotation only 3 times, more simple
 */
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int a = 0;
        int b = n - 1;
        while (a < b) {
            for (int i = 0; i < (b - a); i++) {
                swap(matrix[a][a + i], matrix[a + i][b]);
                swap(matrix[a][a + i], matrix[b][b - i]);
                swap(matrix[a][a + i], matrix[b - i][a]);                
            }
            ++a;
            --b;
        }
    }
};
