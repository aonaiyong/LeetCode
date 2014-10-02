/*
 Author:     naiyong, aonaiyong@gmail.com
 Date:       Oct 2, 2014
 Problem:    Letter Combinations of a Phone Number
 Difficulty: 3
 Source:     https://oj.leetcode.com/problems/letter-combinations-of-a-phone-number/
 Notes:
 Given a digit string, return all possible letter combinations that the number could represent.

 A mapping of digit to letters (just like on the telephone buttons) is given below.

 Input:Digit string "23"
 Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
 Note:
 Although the above answer is in lexicographical order, your answer could be in any order you want.

 Solution:   Depth-first Search.
 */

#ifndef LETTERCOMBINATIONSOFAPHONENUMBER_H_
#define LETTERCOMBINATIONSOFAPHONENUMBER_H_

#include <vector>
using std::vector;

#include <string>
using std::string;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        const vector<string> mapping = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        string letters;
        vector<string> combinations;
        letterCombinations(mapping, digits, letters, combinations);
        return combinations;
    }

    void letterCombinations(const vector<string> &mapping, const string &digits,
                            string &letters, vector<string> &combinations) {
        int depth = letters.size();
        if (depth == digits.size()) {
            combinations.push_back(letters);
            return;
        }

        int d = digits[depth] - '2';
        for (auto c : mapping.at(d)) {
            letters.push_back(c);
            letterCombinations(mapping, digits, letters, combinations);
            letters.pop_back();
        }
    }
};

#endif /* LETTERCOMBINATIONSOFAPHONENUMBER_H_ */
