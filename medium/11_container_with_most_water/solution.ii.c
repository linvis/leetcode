/*
 *Tow Pointer Approach
 *Complexity: O(N)
 *
 *brief:
 *    start from two side, so there are two index, one is 0, the other is (size - 1),
 *    compare the two number, because the max area is decided by the smaller one, 
 *    so, move the smaller's index, recompare the two number, until them meet.
 *
 *This is the first algothrim I think out by myself without see the solution.
 */

int maxArea(int* height, int heightSize) {
    int i, j;
    i = 0;
    j = heightSize - 1;
    int max_area = 0;
    for ( ;i != j;) {
        if (*(height + i) > *(height + j)) {
            int tmp_area =  *(height + j) * (j - i);
            if (tmp_area > max_area)
                max_area = tmp_area;
            j--; 
        } else {
            int tmp_area =  *(height + i) * (j - i);
            if (tmp_area > max_area)
                max_area = tmp_area;
            i++;
        }
    }
    return max_area;
}
