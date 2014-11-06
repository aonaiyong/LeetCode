/*
 Author:      naiyong, aonaiyong@gmail.com
 Date:        Oct 28, 2014
 Problem:     Search in an array that first increases then decreases
 Difficulty:  3
 Source:      http://www.careercup.com/question?id=13579663
 Notes:
 Given an array of integers having the property that first that array is strictly increasing
 then it is strictly decreasing, You have to search for a given number.

 Constraint: Minimize the complexity

 Solution:    Binary Search.
 */

#ifndef SEARCHINCREASINGDECREASINGARRAY_H_
#define SEARCHINCREASINGDECREASINGARRAY_H_

#include <vector>
using std::vector;

#include <functional>
using std::less; using std::greater;

class Solution {
public:
    vector<int> search(const int A[], int n, int target) {
        int peakIndex = peakFinder(A, n);      // find the maximum element
        int i = binarySearch(A, 0, peakIndex, target, less<int>());            // A[0...peakIndex] is sorted
        int j = binarySearch(A, peakIndex + 1, n - 1, target, greater<int>()); // A[peakIndex+1...n-1] is reverse sorted.
        return {i, j};
     }

     // find a peak and return its index
     // Time: O(logn), Space: O(1)
     int peakFinder(const int A[], int n) {
         int low = 0, high = n - 1;
         while (low <= high) {
             int mid = low + (high - low) / 2;
             if (mid > 0 && A[mid - 1] > A[mid])
                 high = mid - 1;
             else if (mid < n - 1 && A[mid] < A[mid + 1])
                 low = mid + 1;
             else
                 return mid;
         }
         return -1;
     }

     // search in A[low...high] for target, return its index if present or -1 if not.
     // A[low...high] is either sorted or reverse sorted.
     template <typename Compare>
     int binarySearch(const int A[], int low, int high, int target, Compare comp) {
         while (low < high) {
             int mid = low + (high - low) / 2;
             if (comp(A[mid], target))
                 low = mid + 1;
             else
                 high = mid;
        }
        if (low == high && A[low] == target)
            return low;
        else
            return -1;
    }
};

#endif /* SEARCHINCREASINGDECREASINGARRAY_H_ */
