/*
 * File name: solu.cpp
 */

/*
 * matrix = [
 *   [1,2,3,4],
 *   [5,1,2,3],
 *   [9,5,1,2]
 * ]
 * 
 * 分两半算，先算上一半
 *   [1,2,3,4],
 *   [ ,1,2,3],
 *   [ , ,1,2]
 * 
 * 再算这一半
 *   [ , , ,],
 *   [5, , ,],
 *   [9,5, ,]
 *
 *   28ms，但是我看了16ms的算法也是这种思路,很奇怪
 */
  

class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {

        for (int i = 0; i < matrix[0].size(); i++) {
            int j = 1, m = i + 1;
            for ( ; j < matrix.size() && m < matrix[0].size(); j++, m++) {
                if (matrix[0][i] != matrix[j][m])
                    return false;
            }
        }
        
        for (int i = 1; i < matrix.size(); i++) {
            int j = i + 1, m = 1;
            for ( ; j < matrix.size() && m < matrix[0].size(); j++, m++) {
                if (matrix[i][0] != matrix[j][m])
                    return false;
            }
        }
        
        return true;
    }
};
