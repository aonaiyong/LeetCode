/*
 Author:     naiyong, aonaiyong@gmail.com
 Date:       Oct 3, 2014
 Problem:    Valid Palindrome
 Difficulty: 2
 Source:     https://oj.leetcode.com/problems/valid-palindrome/
 Notes:
 Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

 For example,
 "A man, a plan, a canal: Panama" is a palindrome.
 "race a car" is not a palindrome.

 Note:
 Have you consider that the string might be empty? This is a good question to ask during an interview.

 For the purpose of this problem, we define empty string as valid palindrome.

 Solution:   Two pointers.
             Time: O(n), Space: O(1).
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
        for (int i = 0, j = s.size() - 1; i < j; ++i, --j) {
            while (i < j && !isalnum(s[i]))
                ++i;
            while (i < j && !isalnum(s[j]))
                --j;

            if (tolower(s[i]) != tolower(s[j]))
                return false;
        }
        return true;
    }
};

#endif /* VALIDPALINDROME_H_ */
