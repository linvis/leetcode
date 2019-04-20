/*
 * File name: solu.cpp
 */

/*
 * 这题和Max Chunks To Make Sorted一样，只不过范围变大了
 * 允许重复值出现了
 * 
 * 但是官方的解法是更好的，实现sort一下，然后判断
 * sum += unsort[i] == sum += sort[i]，说明可以切分
 */

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
            int p_min = 0;
        int p_max = 0;
        stack <pair<int,int>> s;
        
        for (int i = 1; i < arr.size(); i++) {
            
            if (arr[p_max] <= arr[i] && arr[p_min] <= arr[i]) {
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
