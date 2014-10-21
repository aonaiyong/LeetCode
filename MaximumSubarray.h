/*
 Author:      naiyong, aonaiyong@gmail.com
 Date:        Oct 21, 2014
 Problem:     MaximumSubarray.h   
 Difficulty:  
 Source:      
 Notes:
 Solution:
 */

#ifndef MAXIMUMSUBARRAY_H_
#define MAXIMUMSUBARRAY_H_

#include <algorithm>
using std::max;

class Solution {
public:
    int maxSubArray(int A[], int n) {
        int largest = A[0], DP = A[0];
        for (int i = 1; i < n; ++i) {
            DP = max(DP + A[i], A[i]);
            largest = max(largest, DP);
        }
        return largest;
    }
};

#endif /* MAXIMUMSUBARRAY_H_ */
