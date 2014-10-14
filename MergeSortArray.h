/*
 Author:      naiyong, aonaiyong@gmail.com
 Date:        Oct 14, 2014
 Problem:     MergeSortArray.h   
 Difficulty:  
 Source:      
 Notes:
 Solution:
 */

#ifndef MERGESORTARRAY_H_
#define MERGESORTARRAY_H_

class Solution {
public:
	void mergeSort(int A[], int n) {
		int *B = new int[n/2];
		mergeSort(A, 0, n - 1, B);

		delete[] B;
	}

	void mergeSort(int A[], int p, int r, int B[]) {
		if (p < r) {
			int q = p + (r - p) / 2;
			mergeSort(A, p, q, B);
			mergeSort(A, q + 1, r, B);
			merge(A, p, q, r, B);
		}
	}

	void merge(int A[], int p, int q, int r, int B[]) {
		int m = r-q-1;
		for (int i = 0; i <= m; ++i) {
			B[i] = A[i + q + 1];
		}

		int i = q, j = m, k = r;
		while (i >= p && j >= 0)
			A[k--] = A[i] <= B[j] ? B[j--] : A[i--];

		while (j >= 0)
		    A[k--] = B[j--];
	}
};

#endif /* MERGESORTARRAY_H_ */
