/*
 Author:      naiyong, aonaiyong@gmail.com
 Date:        Nov 19, 2014
 Problem:     ZigZag Conversion
 Difficulty:  3
 Source:      https://oj.leetcode.com/problems/zigzag-conversion/
 Notes:
  The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

 P   A   H   N
 A P L S I I G
 Y   I   R

 And then read line by line: "PAHNAPLSIIGYIR"

 Write the code that will take a string and make this conversion given a number of rows:

 string convert(string text, int nRows);

 convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".

 Solution:    Indices of characters on first row in original string are
              0, (nRows - 1) * 2, (nRows - 1) * 4, (nRows - 1) * 6, ...
 */

#ifndef ZIGZAGCONVERSION_H_
#define ZIGZAGCONVERSION_H_

#include <string>
using std::string;

class Solution {
public:
    string convert(string s, int nRows) {
        if (nRows <= 1) return s;

        string z;
        int n = s.size();
        int step = (nRows - 1) * 2;
        for (int i = 0; i < nRows; ++i) {
            for (int j = i; j < n; j += step) {
                z.push_back(s[j]);
                int k = j + step - 2 * i;
                if (i != 0 && i != nRows - 1 && k < n)
                    z.push_back(s[k]);
            }
        }
        return z;
    }
};

#endif /* ZIGZAGCONVERSION_H_ */
