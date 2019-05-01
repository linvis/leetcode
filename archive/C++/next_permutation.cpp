//Time: O(n)
//Space: O(n)
/*
 *brief:
 *    This question is a little confused to understand.
 *    Actually, it can be explain look like this:
 *        give a integer number like: 1234, it has four number "1, 2, 3, 4", 
 *        use these number to create a number bigger than 1234, so it should be 1324,
 *        so why 1324, not 1423, because 1324 is the smallest in numbers bigger than 1234
 */
/*
 *Algorithm:
 *    regard the permutation as a number, find the next number bigger than it.
 */

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int len = nums.size();
        int i = len - 1;
        for ( ; i > 0; i--) {
            //find one number is smaller than the next number
            if (nums.at(i - 1) < nums.at(i)) {
                //find a bigger one
                int j = len - 1;
                for ( ; j >= i; j--) {
                    if (nums.at(i - 1) < nums.at(j)) {
                        break;
                    }
                }
                //swap
                int a = nums.at(i - 1);
                nums.at(i - 1) = nums.at(j);
                nums.at(j) = a;
                //reverse
                reverse(nums.begin() + i, nums.end());
                return;
            }
        }
        //not found
        reverse(nums.begin(), nums.end());
    }
};
