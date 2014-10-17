/*
 Author:      naiyong, aonaiyong@gmail.com
 Date:        Oct 17, 2014
 Problem:     ClimbingStairs.h   
 Difficulty:  
 Source:      
 Notes:
 Solution:
 */

#ifndef CLIMBINGSTAIRS_H_
#define CLIMBINGSTAIRS_H_

#include <vector>
using std::vector;

class Solution {
public:
    int climbStairs(int n) {
        return bottomUpClimbStairsTwoVars(n);
    }

    int memoizedClimbStairs(int n) {
        vector<int> ways(n+1, -1);
        return memoizedClimbStairsAux(n, ways);
    }

    int memoizedClimbStairsAux(int n, vector<int> &ways) {
        if (ways[n] >= 0)
        	return ways[n];

        int m = -1;
        if (n == 1)
        	m = 1;
        else if (n == 2)
        	m = 2;
        else
        	m = memoizedClimbStairsAux(n-1, ways) + memoizedClimbStairsAux(n-2, ways);
        ways[n] = m;
        return m;
    }

    int bottomUpClimbStairs(int n) {
        vector<int> ways(n+1, -1);
        for (int i = 1; i <= n; ++i) {
            int m = -1;
            if (i == 1)
            	m = 1;
            else if (i == 2)
            	m = 2;
            else
            	m = ways[i-1] + ways[i-2];
            ways[i] = m;
        }
        return ways[n];
    }

    int bottomUpClimbStairsTwoVars(int n) {
        int p = 1, q = 1;
        for (int i = 2; i <= n; ++i) {
            int r = p + q;
            p = q;
            q = r;
        }

        return q;
    }

    int ClimbStairsLogn(int n) {

    }
};

#endif /* CLIMBINGSTAIRS_H_ */
