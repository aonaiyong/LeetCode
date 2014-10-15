/*
 Author:      naiyong, aonaiyong@gmail.com
 Date:        Oct 15, 2014
 Problem:     QuickSort (3 way partition)
 Difficulty:  4
 Source:      http://en.wikipedia.org/wiki/Quicksort#Repeated_elements
 Notes:
 Sort an array using quicksort (3 way partition).

 Solution:    http://en.wikipedia.org/wiki/Quicksort#Repeated_elements
              http://www.sorting-algorithms.com/quick-sort-3-way

              1. 3-way partition.
              http://en.wikipedia.org/wiki/Dutch_national_flag_problem

              Loop Invariant:   A  |   < m    |  >= m && <= h  |   ?    |    > h    |
                                    p        i                  j        k         r

              Initialization:   A  |                    ?                           |
                                  i p                                              r k
                                    j

              Termination:      A  |     < m      |   >= m && <= h    |     > h     |
                                    p            i                     k            r
                                                                       j

              2. Choose pivot.
                 Choose median of the first, middle, and last element as pivot.

              3. Property.
                 - Not stable.
                 - Adaptive when few unique keys.
                 - Best-case time: O(n) when O(1) unique keys.
                 - Average-case time: O(nlogn).
                 - Worst-case time: O(n^2).
                 - Worst-case space: O(logn). This is achieved by recursing into the smaller
                   side of the partition, then using a tail call to recurse into the other.
 */

#ifndef QUICKSORT3_H_
#define QUICKSORT3_H_

#include <stack>
using std::stack;

#include <utility>
using std::swap;
using std::pair; using std::make_pair;

class Solution {
    void quickSort3(int A[], int p, int r) {
        if (p < r) {
            int x = A[pivot(A, p, r)];
            pair<int, int> q = partition3(A, p, r, x, x);
            quickSort3(A, p, q.first);
            quickSort3(A, q.second, r);
        }
    }

    void quickSort3Iterative(int A[], int p, int r) {
        stack<pair<int, int>> stk;
        if (p < r)
            stk.push(make_pair(p, r));
	    while (!stk.empty()) {
		    p = stk.top().first;
		    r = stk.top().second;
		    stk.pop();

		    int x = A[pivot(A, p, r)];
		    pair<int, int> q = partition3(A, p, r, x, x);
		    if (q.second < r)
			    stk.push(make_pair(q.second, r));
		    if (p < q.first)
			    stk.push(make_pair(p, q.first));
	    }
    }

    // 3-way partition
    pair<int, int> partition3(int A[], int p, int r, int mid, int high) {
	    int i = p-1, j = p, k = r + 1;
	    while (j < k) {
		    if (A[j] < mid)
			    swap(A[++i], A[j++]);
		    else if (A[j] > high)
			    swap(A[j], A[--k]);
		    else
			    ++j;
	    }
	    return make_pair(i, j);
    }

    int pivot(int A[], int p, int r) {
        return median(A, p, r);
    }

    // median of the first, middle and last element (2-3 comparisons)
    int median(int A[], int p, int r) {
        int q = p + (r - p) / 2;
        if (A[p] < A[q]) {
            if (A[p] > A[r])       // (A[r], A[p], A[q])
                return p;
            else if (A[q] < A[r])  // (A[p], A[q], A[r])
                return q;
        }
        else {
            if (A[q] > A[r])       // (A[r], A[q], A[p])
                return q;
            else if (A[p] < A[r])  // (A[q], A[p], A[r]
                return p;
        }
        return r;                 // (A[p], A[r], A[q]) or (A[q], A[r], A[p])
    }
};

#endif /* QUICKSORT3_H_ */
