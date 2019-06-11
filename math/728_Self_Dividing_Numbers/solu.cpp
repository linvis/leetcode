/*
 * File name: solu.cpp
 */

// 很简单，没什么好说的,注意一些 num % 0 这样的异常就可以了

class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> number;
        
        auto is_self_dividing = [](int num) {
            for (int j = num; j > 0; j = j / 10) {
                if (j % 10 == 0 || num % (j % 10) != 0) {
                    return false;
                }
            }
            return true;
        };
        
        for (int i = left; i <= right; i++) {
            if (is_self_dividing(i))
                number.push_back(i);
        }
        
        return number;
    }
};
