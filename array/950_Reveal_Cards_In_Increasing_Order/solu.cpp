/*
 * File name: solu.cpp
 */

/*
 * 我的思路，因为要获取一个增大的序列，所以我们反向求解，先放上最大值的位置，然后依次放
 * 对于[17,13,11,2,3,5,7], 先反向排序[17,13,11,7,5,3,2]
 * 观察，实际上是
 * 17,
 * 13, 17
 * 13, 17 -> 17, 13 -> 11, 17, 13
 * 11, 17, 13 -> 17, 13, 11 -> 13, 11, 17 -> 7, 13, 11, 17
 * 挨个把前面的元素放到后面
 * 因此我们得到算法
 * 但是我提交后超时了，
 * 这里一个问题是，vector插入到头部是很慢的(O(n)),
 * 插入到尾部是O(1),
 * 第二个问题是，实际上，不用挨个移动前面的元素到尾部，实际上，观察可以发现，只要把队尾元素移到队首就可以了
 */

class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.begin(), deck.end(), [](int a, int b){return a > b;});
        
        vector<int> B;
        
        for (auto d : deck) {
            B = inverseReveal(B, d);
        }   
        
        return B;
    }
    
    vector<int> inverseReveal(vector<int>& B, int n) {
        if (B.size() == 0) {
            B.push_back(n);
        } else {
            for (int i = B.size(); i > 1; i--) {
                int tmp = B[0];
                B.erase(B.begin());
                B.push_back(tmp);
            }
            
            B.insert(B.begin(), n);
        }
        return B;   
    }
};


// ref: https://leetcode.com/problems/reveal-cards-in-increasing-order/discuss/200515/JavaC%2B%2BPython-Simulate-the-Reversed-Process
class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        deque<int> B;
        
        sort(deck.begin(), deck.end(), [](int a, int b){return a > b;});
        B.push_back(deck[0]);
        
        for (int i = 1; i < deck.size(); i++) {
            B.push_front(B.back());     
            B.pop_back();
            B.push_front(deck[i]);
        }
        
        vector<int> res(B.begin(), B.end());
        
        return res;
    }
};
