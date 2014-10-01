/*
 Author:     naiyong, aonaiyong@gmail.com
 Date:       Oct 1, 2014
 Problem:    Word Ladder
 Difficulty: 3
 Source:     https://oj.leetcode.com/problems/word-ladder/
 Notes:
 Given two words (start and end), and a dictionary, find the length of shortest transformation sequence from start to end, such that:

 Only one letter can be changed at a time
 Each intermediate word must exist in the dictionary
 For example,

 Given:
 start = "hit"
 end = "cog"
 dict = ["hot","dot","dog","lot","log"]
 As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
 return its length 5.

 Note:
 Return 0 if there is no such transformation sequence.
 All words have the same length.
 All words contain only lower-case alphabetic characters.

 Solution:
 */

#ifndef WORDLADDER_H_
#define WORDLADDER_H_

#include <string>
using std::string;

#include <unordered_set>
using std::unordered_set;

#include <queue>
using std::queue;


class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        int len = 1;
        queue<string> frontier;
        frontier.push(start);
        while (!frontier.empty()) {
            ++len;

            // iterate through all words in current level
            int m = frontier.size();
            for (int i = 0; i < m; ++i) {
                string word = frontier.front();
                frontier.pop();

                int n = word.size();
                for (int j = 0; j < n; ++j) {
                    char temp = word[j];
                    for (char c = 'a'; c <= 'z'; ++c) {
                        word[j] = c;
                        if (word == end) return len;

                        if (dict.count(word)) {
                            dict.erase(word);
                            frontier.push(word);
                        }
                    } // character loop
                    word[j] = temp;
                } // position loop
            } // word loop
        } // frontier loop

        return 0;
    }
};

#endif /* WORDLADDER_H_ */
