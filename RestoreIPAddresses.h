/*
 Author:     naiyong, aonaiyong@gmail.com
 Date:       Oct 2, 2014
 Problem:    Restore IP Addresses
 Difficulty: 3
 Source:     https://oj.leetcode.com/problems/restore-ip-addresses/
 Notes:
 Given a string containing only digits, restore it by returning all possible valid IP address combinations.

 For example:
 Given "25525511135",

 return ["255.255.11.135", "255.255.111.35"]. (Order does not matter)

 Solution:   Depth-first Search.
 */

#ifndef RESTOREIPADDRESSES_H_
#define RESTOREIPADDRESSES_H_

#include <vector>
using std::vector;

#include <string>
using std::string;

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> combinations;
        string ip;
        restoreIpAddresses(s, 0, 0, ip, combinations);
        return combinations;
    }

    void restoreIpAddresses(const string &s, int depth, int pos, string ip, vector<string> &combinations) {
        if (depth == 4 && pos == s.size()) {
            ip.resize(ip.size()-1);
            combinations.push_back(ip);
        }
        if (depth == 4) return;

        int num = 0;
        for (int i = pos; i < s.size(); ++i) {
            num = num * 10 + s[i] - '0';
            if (num > 255) break;
            ip += s[i];
            restoreIpAddresses(s, depth + 1, i + 1, ip + '.', combinations);
            if (!num) break;
        }
    }
};

#endif /* RESTOREIPADDRESSES_H_ */
