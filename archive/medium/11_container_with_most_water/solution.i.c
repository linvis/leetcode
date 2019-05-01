/*
 *Brute force version
 *iterate every two element
 *Complexity: O(N2)
 *
 *Time Limit exceeded
 */

int maxArea(int* height, int heightSize) {
    int i, j;
    int max_area = 0;
    
    for (i = 0; i < heightSize; i++) {
        for (j = 0; j < heightSize; j++) {
            int tmp_area = (j - i) * (*(height + i) < *(height + j) ? *(height + i) : *(height + j));
            if (tmp_area > max_area) 
                max_area = tmp_area;
        }
    }
    return max_area;
}
