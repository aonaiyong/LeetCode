/*
 Author:      naiyong, aonaiyong@gmail.com
 Date:        Oct 23, 2014
 Problem:     StringMatchingContentLength.h   
 Difficulty:  
 Source:      
 Notes:
 Solution:
 */

#ifndef STRINGMATCHINGCONTENTLENGTH_H_
#define STRINGMATCHINGCONTENTLENGTH_H_

#include <string>
using std::string;

#include <vector>
using std::vector;

#include <algorithm>
using std::max;

#include <iostream>
using std::cout; using std::endl;

class Solution {
public:
    typedef vector<int> VEC1D;
    typedef vector<vector<int> > VEC2D;

    int SMCLength(const string &x, const string &y) {
        int m = x.size(), n = y.size();
        VEC2D DP(m+1, VEC1D(n+1));
        VEC2D cnt(m+1, VEC1D(n+1));
        for (int i = 1; i <= m; ++i)
            for (int j = 1; j <= n; ++j)
                if (x[i-1] == y[j-1])
                    DP[i][j] = DP[i-1][j-1] + 1;
                else
                    DP[i][j] = 0;
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j)
                cout << DP[i][j] << "  ";
            cout << endl;
        }
        cout << endl << endl;

        int largest = 0;
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                int len = DP[i][j];
                if (len >= 3)
                    cnt[i][j] = len + cnt[i-len][j-len];
                else
                    cnt[i][j] = max(max(cnt[i-1][j], cnt[i][j-1]), cnt[i-1][j-1]);
                largest = max(largest, cnt[i][j]);
            }
        }

        for (int i = 1; i <= m; ++i) {
              for (int j = 1; j <= n; ++j)
                  cout << cnt[i][j] << "  ";
              cout << endl;
        }

        return largest;
    }
};

#endif /* STRINGMATCHINGCONTENTLENGTH_H_ */
