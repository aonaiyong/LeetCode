/*
 Author:     naiyong, aonaiyong@gmail.com
 Date:       Sep 23, 2014
 Problem:    LengthOfLastWord.h
 Difficulty: 1
 Source:     https://oj.leetcode.com/problems/length-of-last-word/
 Notes:
 Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.

 If the last word does not exist, return 0.

 Note: A word is defined as a character sequence consists of non-space characters only.

 For example,
 Given s = "Hello World",
 return 5.

 Solution:   Note that trailing space should be ignored.
 */

#ifndef LENGTHOFLASTWORD_H_
#define LENGTHOFLASTWORD_H_

#include <cstring>

class Solution {
public:
    int lengthOfLastWord(const char *s) {
        int len = 0;
        int n = strlen(s);
        for (int i = n - 1; i >= 0; --i) {
            if (s[i] != ' ') 
                ++len;
            else if (len) 
                break;    // ignore trailing space
        }

        return len;
    }
};

#endif /* LENGTHOFLASTWORD_H_ */
