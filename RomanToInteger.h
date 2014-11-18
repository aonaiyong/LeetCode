/*
 Author:      naiyong, aonaiyong@gmail.com
 Date:        Nov 18, 2014
 Problem:     Roman to Integer
 Difficulty:  2
 Source:      https://oj.leetcode.com/problems/roman-to-integer/
 Notes:
 iven a roman numeral, convert it to an integer.

 Input is guaranteed to be within the range from 1 to 3999.

 Solution:    Roman numerals. http://en.wikipedia.org/wiki/Roman_numerals
 */

#ifndef ROMANTOINTEGER_H_
#define ROMANTOINTEGER_H_

#include <string>
using std::string;

#include <unordered_map>
using std::unordered_map;

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> mapping = { {'M', 1000}, {'D', 500}, {'C', 100}, {'L', 50}, {'X', 10}, {'V', 5}, {'I', 1} };
        int num = 0, n = s.size();
        for (int i = 0; i < n; ++i) {
            if (i < n - 1 && mapping[s[i]] < mapping[s[i+1]]) // Cases: "CM", "CD", "XC", "XL", "IX", "IV"
                num -= mapping[s[i]];
            else
                num += mapping[s[i]];
        }
        return num;
    }
};

#endif /* ROMANTOINTEGER_H_ */
