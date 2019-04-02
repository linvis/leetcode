/*
 * File name: solu.cpp
 */

// ref: https://leetcode.com/problems/complex-number-multiplication/discuss/156634/6-lines-C%2B%2B-solutions-using-regexstringstream
//
// here is a fucking thing, I know the algorithm, but I am not familiar with C++ regex
// I had wasted much time to find how to use C++ regex
// what a fucking thing

class Solution {
public:
    string complexNumberMultiply(string a, string b) {
        smatch ma, mb;
        regex pattern(R"((-?\d+)\+(-?\d+)i)");
        regex_match(a, ma, pattern);
        regex_match(b, mb, pattern);
        int r1 = stoi(ma[1]), i1 = stoi(ma[2]), r2 = stoi(mb[1]), i2 = stoi(mb[2]);
        return to_string(r1 * r2 - i1 * i2) + '+' + to_string(r1 * i2 + r2 * i1) + 'i';
    }
};
