/*
 *Dynamic version
 *
 *According to https://discuss.leetcode.com/topic/25500/share-my-java-solution-using-dynamic-programming
 *
 * if Si....Sj is a palindrome, and Si-1 == Sj+1, so Si-1...Sj+1 must be a palindrome 
 *
 *complexity: O(N2)
 *space:		O(N2)
 */

char* longestPalindrome(char* s) {
    int i, j;
    int n = strlen(s);
    int p[n][n];
    memset(p, 0, sizeof(p));
    int max_len = 0;
    int min = 0;
    int max = 0;

    for (i = n - 1; i >= 0; i--) {
        for (j = i; j < n; j++) {
            if ( (*(s + i) == *(s + j)) && (j - i < 3 || p[i + 1][j - 1])) {
                p[i][j] = 1;
                if (max_len < (j - i + 1)) {
                    max_len = j - i + 1;
                    min = i;
                    max = j;
                }
            }
        }
    }
    
    char *re = malloc(max_len + 1);
    memcpy(re, s + min, max_len);
    *(re + max_len) = '\0';
    return re;
}
