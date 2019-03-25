/*
 * File name: solu.cpp
 */

/*
 * 这题很简单
 * 我的第一次提交是60ms
 * 第二次，我改成了
 * for (auto t : timeSeries) {
 *     if (t >= end) {
 *         sum += end - start;
 *         start = t;
 *     }
 *     end = t + duration;
 * }
 * 理论上，应该更快才对，但实际提交跑了72ms，很奇怪,它的时间复杂度分析似乎不太靠谱,
 */

class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int start = 0, end = 0;
        int sum = 0;
        
        for (auto t : timeSeries) {
            if (t >= end) {
                sum += end - start;
                start = t;
                end = t + duration;
            } else {
                end = t + duration;
            }
        }
        sum += end - start;
        return sum;
    }
};
