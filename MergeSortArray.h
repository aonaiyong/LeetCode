/*

 Author:      naiyong, aonaiyong@gmail.com
 Date:        Oct 14, 2014
 Problem:     Merge Sort Array
 Difficulty:  3
 Source:      http://en.wikipedia.org/wiki/Merge_sort
 Notes:
 Sort an array using merge sort.

 Solution:    http://en.wikipedia.org/wiki/Merge_sort
              http://www.sorting-algorithms.com/merge-sort

              1. Tow-down recursive implementation.

                 Divide:   A  |              |              |
                               p            q q+1          r    q = p + (r-p)/2

                 Conquer:  A   |      <      |       <      |
                                p           q q+1          r

                                           B |       <      |
                                              0            m    m = r-q-1
                          B[0...m] is a copy of A[q+1...r].

                 Combine:  A   |             <              |
                                p                          r

              2. Bottom-up iterative implementation.

              Time: O(nlogn), Space: n/2

              For tow-down implementation, the recursion tree is guaranteed to be balanced.
              For bottom-up implementation, the tree might be unbalanced.
 */

#ifndef MERGESORTARRAY_H_
#define MERGESORTARRAY_H_

#include <algorithm>
using std::min;

class Solution {
public:
	void mergeSort(int A[], int n) {
		int *B = new int[n/2];
		// topDownMergeSort(A, 0, n - 1, B);
		bottomUpMergeSort(A, n, B);

		delete[] B;
	}

	void bottomUpMergeSort(int A[], int n, int B[]) {
		// width denotes subset size
		for (int width = 1; width < n; width <<= 1) {
			// Merge consecutive subsets
			for (int i = 0; i < n; i += 2 * width)
				merge(A, i, min(i+width, n) - 1, min(i+2*width, n) - 1, B);
		}
	}

	// Both p and r are inclusive
	void topDownMergeSort(int A[], int p, int r, int B[]) {
		if (p < r) {                          // Initial range A[p...r], where p < r
			int q = p + (r - p) / 2;          // p <= q < r
			topDownMergeSort(A, p, q, B);     // Reduced range A[p...q]
			topDownMergeSort(A, q + 1, r, B); // Reduced range A[q+1...r]
			merge(A, p, q, r, B);             // Merge sorted array A[p...q] and A[q+1...r]
		}
	}

	// Merge two sorted array A[p...q] and A[q+1...r]
	// Note that A[q+1...r] might be empty (r <= q)
	void merge(int A[], int p, int q, int r, int B[]) {
		int m = r-q-1;           // m is inclusive
		// Copy A[q+1...r] into B[0...m]
		for (int i = 0; i <= m; ++i) {
			B[i] = A[i + q + 1];
		}

		// Merge A[p...q] and B[0...m]
		int i = q, j = m, k = r;  // i, j, and k are all inclusive
		while (i >= p && j >= 0)
			A[k--] = A[i] <= B[j] ? B[j--] : A[i--];

		while (j >= 0)
		    A[k--] = B[j--];
	}
};

#endif /* MERGESORTARRAY_H_ */
