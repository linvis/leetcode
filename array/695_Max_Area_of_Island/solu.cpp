/*
 * File name: solu.cpp
 */

/*
 * 这题的解题思路是这样的，
 * 很明显，要用DP做，状态转移方程：
 * Fn+1 = max(Fn, An+1)
 * An+1怎么求呢, 对于任意一个island(即grid[i][j] == 1), 
 * An+1 = up + right + down + left
 * 即，只要找到一个点等于1，然后求上下左右四个方向上的1的数量(各自递归求解),
 * 就得到答案了
 * 这里我找到1后，让该点为-1，是为了避免重复求解
 */

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea = 0;
        int nodeMaxArea = 0;
       
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) {
                    grid[i][j] = -1;
                    nodeMaxArea = 1 + findMaxArea(grid, i, j);
                    maxArea = max(maxArea, nodeMaxArea);
                }
            }
        }
        
        return maxArea;
    }
    
    int findMaxArea(vector<vector<int>>& grid, int i, int j) {
        int up = 0, right = 0, down = 0, left = 0;
        int ori_i = i, ori_j = j;
        
        if (--i >= 0) {
            if (grid[i][j] == 1) {
                up++;
                grid[i][j] = -1;
                up += findMaxArea(grid, i, j);
            }
        } 
        
        i = ori_i;
        if (++j < grid[0].size()) {
            if (grid[i][j] == 1) {
                right++;
                grid[i][j] = -1;
                right += findMaxArea(grid, i, j);
            }
        } 
        
        j = ori_j;
        if (++i < grid.size()) {
            if (grid[i][j] == 1) {
                down++;
                grid[i][j] = -1;
                down += findMaxArea(grid, i, j);
            }
        } 
        
        i = ori_i;
        if (--j >= 0) {
            if (grid[i][j] == 1) {
                left++;
                grid[i][j] = -1;
                left += findMaxArea(grid, i, j);
            }
        } 
        
        return (up + right + down + left);
    }
};
