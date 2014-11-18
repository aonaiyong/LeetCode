/*
 Author:      naiyong, aonaiyong@gmail.com
 Date:        Nov 18, 2014
 Problem:     Count and Say
 Difficulty:  2
 Source:      https://oj.leetcode.com/problems/count-and-say/
 Notes:
 The count-and-say sequence is the sequence of integers beginning as follows:
 1, 11, 21, 1211, 111221, ...

 1 is read off as "one 1" or 11.
 11 is read off as "two 1s" or 21.
 21 is read off as "one 2, then one 1" or 1211.
 Given an integer n, generate the nth sequence.

 Note: The sequence of integers will be represented as a string.

 Solution:    1. find_first_not_of.
              2. iteration.
 */

#ifndef COUNTANDSAY_H_
#define COUNTANDSAY_H_

#include <string>
using std::string;

#include <sstream>
using std::stringstream;

class Solution {
public:
    string countAndSay(int n) {
        return countAndSayIter(n);
    }

    // find_first_not_of
    string countAndSayStr(int n) {
        string s("1");
        for (int i = 2; i <= n; ++i) {
            stringstream ss;
            size_t pos = 0, start = 0;
            while ((pos = s.find_first_not_of(s[start], start)) != string::npos) {
                ss << pos - start << s[start];
                start = pos;
            }
            ss << s.size() - start << s[start];

            ss >> s;
        }
        return s;
    }

    // iteration
    string countAndSayIter(int n) {
        string s("1");
        for (int i = 2; i <= n; ++i) {
            stringstream ss;
            int j = 0, sz = s.size();
            while (j < sz) {
                int k = j + 1;
                while (k < sz && s[k] == s[k-1])
                    ++k;
                ss << k - j << s[j];
                j = k;
            }
            ss >> s;
        }
        return s;
    }
};

#endif /* COUNTANDSAY_H_ */
