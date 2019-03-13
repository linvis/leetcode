/*
 * File name: solu.cpp
 */

// 这道题思路很简单，找到'R'，然后往上下左右四个方向遍历，直到先遇到'p'，认为有效，
// 遇到'B'，认为无效

class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {

        vector<int> rook = getRook(board);
        
        return reachPawn(board, rook[0], rook[1]);        
    }
    
    vector<int> getRook(vector<vector<char>>& board) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if(board[i][j] == 'R')
                    return {i, j};
            }
        }
        
        return {-1, -1};
    }
    
    int reachPawn(vector<vector<char>>& board, int row, int col) {
        int count = 0;
        
        if (row < 0 || col < 0)
            return 0;
        
        for (int i = row - 1; i >= 0; i--) {
            if(board[i][col] == '.')
                continue;
            if(board[i][col] == 'B')
                break;
            if(board[i][col] == 'p') {
                count++;
                break;
            }
        }
        
        for (int i = row + 1; i < board.size(); i++) {
            if(board[i][col] == '.')
                continue;
            if(board[i][col] == 'B')
                break;
            if(board[i][col] == 'p') {
                count++;
                break;
            }
        }
        for (int j = col - 1; j >= 0; j--) {
            if(board[row][j] == '.')
                continue;
            if(board[row][j] == 'B')
                break;
            if(board[row][j] == 'p') {
                count++;
                break;
            }
        }
        for (int j = col + 1; j < board[0].size(); j++) {
            if(board[row][j] == '.')
                continue;
            if(board[row][j] == 'B')
                break;
            if(board[row][j] == 'p') {
                count++;
                break;
            }
        }
        return count;
    }
};
