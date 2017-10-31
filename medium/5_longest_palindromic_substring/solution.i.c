/*
 *Brute force version
 *
 *palindrome string has two type:
 *    1. xxYxx
 *    2. xxxx
 *
 *so base on it, get one character, judge its either side whether conform the two type, until the string's end.
 *Like:
 *        ----------------------
 *        |       cabacd       |
 *        |     <---|--->      |
 *        |____________________|
 */

/*
 *complexity is O(N3)
 *for each type, I iterate (1 + 2 + .... N/2)(because if the left_idx or right_idx is bigger then N/2, it will break for loop)
 *the complexity is O(N2),
 *so the sum is N * O(N2) = O(N3)
 */

char* longestPalindrome(char* s) {
    int left_idx = 0;
    int left_end = 0;
    int right_idx = 0;
    int right_end = strlen(s) - 1;
    int max_len = 1;
    char* center = s;
    int i = 0;
    
    for ( ; i < strlen(s); i++) {
            left_idx = 1;
            right_idx = 1;
            char* c = s + i;
            
            /*
             *get char c, then compare its either side, whether them are equal, if equal, judge whether update max_len 
             */
            for ( ;(i - left_idx) >= left_end && (right_idx + i) <= right_end;left_idx++, right_idx++ ) {
                if (*(c - left_idx) == *(c + right_idx)) {
                    if ((left_idx * 2 + 1) >= max_len) {
                        max_len = left_idx * 2 + 1;
                        center = c;
                    } 
                } else 
                    break;
            }
            /*
             *get char c, then compare c and its right side, whether them are equal, if equal, judge whether update max_len 
             */
            left_idx = 1;
            right_idx = 1;
            for ( ;(i - left_idx + 1) >= left_end && (right_idx + i) <= right_end;left_idx++, right_idx++ ) {
                if (*(c - left_idx + 1) == *(c + right_idx)) {
                    if ((left_idx * 2) >= max_len) {
                        max_len = left_idx  * 2;
                        center = c;
                    } 
                } else 
                    break;
            }            
        }
    char *result = malloc((max_len + 1) * sizeof(char));
    memset(result, max_len, 0);
    if (max_len % 2) {
        memcpy(result, center - (max_len) / 2, max_len);
    } else {        
        memcpy(result, center - (max_len - 1) / 2, max_len);
    }
    /*
     *Here for leetcode.com's testing, 
     *I must add a end character, I guess its testing program maybe use a string to copy the result,
     *and to compare with the expected, but the string is not initialized.
     *Failed case:
     *    string:     "dddddddd"
     *    output:     "dddddddd\""
     *    expected:   "dddddddd"
     *I tested this case under GCC, it work successful.
     */
    *(result + max_len) = '\0';
    return result;
}
