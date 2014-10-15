/*
 Author:      naiyong, aonaiyong@gmail.com
 Date:        Oct 15, 2014
 Problem:     HeapSort.h   
 Difficulty:  
 Source:      
 Notes:
 Solution:
 */

#ifndef HEAPSORT_H_
#define HEAPSORT_H_

#include <utility>
using std::swap;

#define PARENT(i)  ((i-1)/2)
#define LEFT(i)    (2*i+1)
#define RIGHT(i)   (2*i+2)

class Solution {
public:
    void maxHeapify(int A[], int n, int i) {
        int l = LEFT(i), r = RIGHT(i);
        int largest = i;
        if (l < n && A[l] > A[i])
            largest = l;
        if (r < n && A[r] > A[largest])
            largest = r;
        if (largest != i) {
            swap(A[i], A[largest]);
            maxHeapify(A, n, largest);
        }
    }

    void buildMaxHeap(int A[], int n) {
        for (int i = PARENT(n); i >= 0; --i) {
            maxHeapify(A, n, i);
        }
    }

    void heapSort(int A[], int n) {
        buildMaxHeap(A, n);
        for (int i = n-1; i >= 1; --i) {
            swap(A[0], A[i]);
            maxHeapify(A, i, 0);
        }
    }
};


#endif /* HEAPSORT_H_ */
