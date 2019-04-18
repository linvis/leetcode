/*
 * File name: solu.cpp
 */


/*
 * 做这题的时候，我忽略了规则:
 * arr[i] will be a permutation of [0, 1, ..., arr.length - 1]
 * 这条规则，说明每个chunks，max(chunks) = i
 * 
 * 我没注意到这个规则，所以写的更common了
 * 我的思路是，分成chunks的 A, B, C
 * 有 max(A) < max(B) < max(C)
 * 和 min(A) < min(B) < min(C) 这两个规则
 * 所以，我首先判断 A和B，符合规则，把A压栈，
 * 然后判断 B和C，符合规则，再把A取出来，判断A和C符不符合规则，
 * 这样，最后栈里，剩余的就是符合规则的
 */

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int p_min = 0;
        int p_max = 0;
        stack <pair<int,int>> s;
        
        for (int i = 1; i < arr.size(); i++) {
            
            if (arr[p_max] < arr[i] && arr[p_min] < arr[i]) {
                s.push(make_pair(p_min, p_max));
                p_max = i;
                p_min = i;
            } else {
                p_max = arr[p_max] > arr[i] ? p_max : i;
                p_min = arr[p_min] < arr[i] ? p_min : i;
                while (!s.empty()) {
                    pair <int, int> p = s.top();
                    if (arr[p.first] > arr[p_min] || arr[p.second] > arr[p_min]) {
                        s.pop();
                    } else {
                        break;
                    }
                }
            }
        }
        return (s.size() + 1);
    }
};


// 官方的solution，有点取巧的感觉，不过这是规则允许的
class Solution {
    public int maxChunksToSorted(int[] arr) {
        int ans = 0, max = 0;
        for (int i = 0; i < arr.length; ++i) {
            max = Math.max(max, arr[i]);
            if (max == i) ans++;
        }
        return ans;
    }
}
