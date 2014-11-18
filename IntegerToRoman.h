/*
 Author:      naiyong, aonaiyong@gmail.com
 Date:        Nov 18, 2014
 Problem:     Integer to Roman
 Difficulty:  3
 Source:      https://oj.leetcode.com/problems/integer-to-roman/
 Notes:
 Given an integer, convert it to a roman numeral.

 Input is guaranteed to be within the range from 1 to 3999.

 Solution:    Roman numerals. http://en.wikipedia.org/wiki/Roman_numerals
 */

#ifndef INTEGERTOROMAN_H_
#define INTEGERTOROMAN_H_

#include <string>
using std::string;

#include <cmath>
using std::pow;

#include <vector>
using std::vector;

#include <utility>
using std::pair;

class Solution {
public:
    string intToRoman(int num) {
        return intToRoman_2(num);
    }

    string intToRoman_1(int num) {
        const string mapping[4][10] = { {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"}, // 1-9
                                        {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"}, // 10-90
                                        {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"}, // 100-900
                                        {"", "M", "MM", "MMM"} }; // 1000-3000
        string roman;
        int i = 3;
        while (num > 0) {
            int divisor = static_cast<int>(pow(10, i));
            roman += mapping[i][num / divisor];
            num %= divisor;
            --i;
        }
        return roman;
    }

    string intToRoman_2(int num) {
        const vector<pair<int, string> > mapping = { {1000, "M"},
                                                     {900, "CM"}, {500, "D"}, {400, "CD"}, {100, "C"},
                                                     {90, "XC"}, {50, "L"}, {40, "XL"}, {10, "X"},
                                                     {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"} };
        string roman;
        for (int i = 0; num > 0 && i < mapping.size(); ++i) {
            while (num >= mapping[i].first) {
                roman += mapping[i].second;
                num -= mapping[i].first;
            }
        }
        return roman;
    }
};

#endif /* INTEGERTOROMAN_H_ */
