/*
 Author:      naiyong, aonaiyong@gmail.com
 Date:        Oct 14, 2014
 Problem:     QuickSort
 Difficulty:  3
 Source:      http://en.wikipedia.org/wiki/Quicksort
 Notes:
 Sort an array using Quicksort.

 Solution:    http://en.wikipedia.org/wiki/Quicksort
              http://www.sorting-algorithms.com/quick-sort

              1. 2-way partition.

              Loop Invariant:   A  |    <=x     |    >x     |     ?     |x|
                                    p          i             j           r

              Initialization:   A  |                                    |x|
                                  i p                                    r
                                    j

              Termination:      A  |       <=x       |        >x        |x|
                                    p               i                    r
                                                                         j

                                A  |       <=x       |x|      >x          |
                                    p               i q                  r
                                                                         j
               2. Choose pivot.
                                A  |                                      |
                                    p                  q                 r
                  choose median of A[p], A[q], and A[r] as pivot.

               3. Property.
                  - Not stable.
                  - Not adaptive.
                  - Best-case time: O(nlogn).
                  - Average-case time: O(nlogn).
                  - Worst-case time: O(n^2)
                  - Worst-case space: O(logn). This is achieved by recursing into the smaller
                    side of the partition, then using a tail call to recurse into the other.
 */

#ifndef QUICKSORT_H_
#define QUICKSORT_H_

#include <stack>
using std::stack;

#include <utility>
using std::swap;
using std::pair; using std::make_pair;

class Solution {
public:
    // Both p and r are inclusive
    void quickSort(int A[], int p, int r) {
        if (p < r) {                    // initial range A[p...r]
            int q = partition(A, p, r); // p <= q and q <= r
            quickSort(A, p, q - 1);     // reduced range A[p...q-1]
            quickSort(A, q + 1, r);     // reduced range A[q+1...r]
        }
    }

    void quickSortIterative(int A[], int p, int r) {
        stack<pair<int, int>> stk;
        if (p < r)
            stk.push(make_pair(p, r));
        while (!stk.empty()) {
            p = stk.top().first;
            r = stk.top().second;
            stk.pop();

            int q = partition(A, p, r);
            if (q+1 < r)
                stk.push(make_pair(q+1, r));
            if (p < q-1)
                stk.push(make_pair(p, q-1));
        }
    }

    // 2-way partition
    int partition(int A[], int p, int r) {
        // choose a pivot element from A[p...r]
        // and exchange it and A[r]
        int q = pivot(A, p, r), x = A[q];
        swap(A[q], A[r]);

        int i = p - 1;
        for (int j = p; j < r; ++j) {
            if (A[j] <= x)
                swap(A[++i], A[j]);
        }
        swap(A[i+1], A[r]);

        return i+1;
    }

    int pivot(int A[], int p, int r) {
        return median(A, p, r);
    }

    // median of the first, middle and last element (2-3 comparisons)
    int median(int A[], int p, int r) {
        int q = p + (r - p) / 2;
        if (A[p] < A[q]) {
            if (A[r] < A[p])       // (A[r], A[p], A[q])
                return p;
            else if (A[q] < A[r])  // (A[p], A[q], A[r])
                return q;
        }
        else {
            if (A[r] < A[q])       // (A[r], A[q], A[p])
                return q;
            else if (A[p] < A[r])  // (A[q], A[p], A[r]
                return p;
        }
        return r;                 // (A[p], A[r], A[q]) or (A[q], A[r], A[p])
    }
};

#endif /* QUICKSORT_H_ */
