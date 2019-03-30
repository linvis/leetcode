/*
 * File name: solu.cpp
 */

class Solution {
public:
    bool judgeCircle(string moves) {
        int pos_x = 0, pos_y = 0;
        
        for (auto c : moves) {
            auto move = [](char c, int &x, int &y) {
                switch (c) {
                    case 'U':
                    y--;
                    break;
                    case 'D':
                    y++;
                    break;
                    case 'L':
                    x--;
                    break;
                    case 'R':
                    x++;
                    break;
                }
            };
            
            move(c, pos_x, pos_y);
        }
        
        return (pos_x == 0 && pos_y == 0);
    }
};
