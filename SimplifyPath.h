/*
 Author:      naiyong, aonaiyong@gmail.com
 Date:        Nov 16, 2014
 Problem:     Simplify Path
 Difficulty:  3
 Source:      https://oj.leetcode.com/problems/simplify-path/
 Notes:
 Given an absolute path for a file (Unix-style), simplify it.

 For example,
 path = "/home/", => "/home"
 path = "/a/./b/../../c/", => "/c"

 Corner Cases:

     Did you consider the case where path = "/../"?
     In this case, you should return "/".
     Another corner case is the path might contain multiple slashes '/' together, such as "/home//foo/".
     In this case, you should ignore redundant slashes and return "/home/foo".

 Solution:
 */

#ifndef SIMPLIFYPATH_H_
#define SIMPLIFYPATH_H_

#include <string>
using std::string;

#include <stack>
using std::stack;

class Solution {
public:
    string simplifyPath(string path) {
        return simplifyPathStack(path);
    }

    string simplifyPathString(string &path) {
        path += '/';
        string result;
        size_t pos = 0, start = 0;
        while ((pos = path.find_first_of('/', start)) != string::npos) {
            string s = path.substr(start, pos - start);
            if (s == "..") {
                if (!result.empty())
                    result.resize(result.find_last_of('/'));
            }
            else if (!s.empty() && s != ".")
                result += '/' + s;

            start = pos + 1;
        }
        return result.empty() ? "/" : result;
    }

    string simplifyPathStack(string &path) {
        path += '/';
        stack<string> stk;
        size_t pos = 0, start = 0;
        while ((pos = path.find_first_of('/', start)) != string::npos) {
            string s = path.substr(start, pos - start);
            if (s == "..") {
                if (!stk.empty())
                    stk.pop();
            }
            else if (!s.empty() && s != ".")
                stk.push(s);

            start = pos + 1;
        }

        if (stk.empty())
            return "/";
        string result;
        while (!stk.empty()) {
            result.insert(0, "/" + stk.top());
            stk.pop();
        }
        return result;
    }
};

#endif /* SIMPLIFYPATH_H_ */
