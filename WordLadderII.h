/*
 Author:     naiyong, aonaiyong@gmail.com
 Date:       Oct 1, 2014
 Problem:    WordLadderII.h
 Difficulty: 4
 Source:     https://oj.leetcode.com/problems/word-ladder-ii/
 Notes:
 Given two words (start and end), and a dictionary, find all shortest transformation sequence(s) from start to end, such that:

 Only one letter can be changed at a time
 Each intermediate word must exist in the dictionary
 For example,

 Given:
 start = "hit"
 end = "cog"
 dict = ["hot","dot","dog","lot","log"]
 Return
  [
    ["hit","hot","dot","dog","cog"],
    ["hit","hot","lot","log","cog"]
  ]
 Note:
 All words have the same length.
 All words contain only lower-case alphabetic characters.

 Solution:   Two steps:
             1. Compute all shortest-paths from start to end (BFS).
             2. Build all shortest-paths from start to end (DFS).
 */

#ifndef WORDLADDERII_H_
#define WORDLADDERII_H_

#include <vector>
using std::vector;

#include <string>
using std::string;

#include <unordered_set>
using std::unordered_set;

#include <map>
using std::map;

#include <queue>
using std::queue;

class Solution {
public:
    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
        map<string, vector<string>> traces;
        queue<string> frontier;
        frontier.push(start);
        bool isFound = false;
        while (!frontier.empty()) {
            unordered_set<string> visited;

            // iterate through all words in current frontier (level)
            int n = frontier.size();
            for (int i= 0; i < n; ++i) {
                string word = frontier.front();
                frontier.pop();

                // iterate through all positions in current word
                string trans = word;
                for (auto &c : trans) {
                    char d = c;
                    for (c = 'a'; c <= 'z'; ++c) {
                        if (dict.count(trans)) {
                            traces[trans].push_back(word);
                            visited.insert(trans);
                        }
                    }
                    c = d;
                } // position loop
            } // word loop

            if (visited.count(end)) {
                isFound = true;
                break;
            }

            // build new frontier and update dict
            for (const auto &word : visited) {
                frontier.push(word);
                dict.erase(word);
            }
        }

        vector<vector<string>> ladders;
        vector<string> path;
        if (isFound) {
            buildLadders(traces, ladders, path, start, end);
        }
        return ladders;
    }

    void buildLadders(const map<string, vector<string>> &traces, vector<vector<string>> &ladders,
                      vector<string> &path, const string &start, const string &end) {
        if (end == start) {
            vector<string> res(path);
            res.push_back(start);
            reverse(res.begin(), res.end());
            ladders.push_back(res);
            return;
        }

        path.push_back(end);
        for (const auto &word : traces.at(end)) {
            buildLadders(traces, ladders, path, start, word);
        }
        path.pop_back();
    }
};

#endif /* WORDLADDERII_H_ */
