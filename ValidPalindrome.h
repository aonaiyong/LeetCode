/*
 Author:     naiyong, aonaiyong@gmail.com
 Date:       Oct 3, 2014
 Problem:    Valid Palindrome
 Difficulty:
 Source:
 Notes:

 Solution:
 */

#ifndef VALIDPALINDROME_H_
#define VALIDPALINDROME_H_

#include <string>
using std::string;

#include <cctype>
using std::isalnum; using std::tolower;

class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0, j = s.size() - 1;
        while (i < j) {
            while (i < j && !isalnum(s[i])) ++i;
            while (i < j && !isalnum(s[j])) --j;

            if (tolower(s[i++]) != tolower(s[j--])) return false;
        }

        return true;
    }
};

#endif /* VALIDPALINDROME_H_ */
