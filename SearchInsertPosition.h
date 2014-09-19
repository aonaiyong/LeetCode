/*
 * Author:     naiyong, aonaiyong@gmail.com
 * Date:       Sep 19, 2014
 * Problem:    SearchInsertPosition.h
 * Difficulty: TODO
 * Source:     TODO
 * Notes:	   TODO
 * Solution:   TODO
 */

#ifndef SEARCHINSERTPOSITION_H_
#define SEARCHINSERTPOSITION_H_

class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        return searchInsert3B(A, n, target);
    }

    // 3 branches & iterative
    int searchInsert3B(int A[], int n, int target) {
        int low = 0, top = n - 1;
        while (low <= top) {
            int mid = low + (top - low) / 2;
            if (A[mid] == target) {
                return mid;
            }
            else if(A[mid] < target) {
                low = mid + 1;
            }
            else {
                top = mid - 1;
            }
        }

        return low;
    }

    // 2 branches & iterative
    int searchInsert2B(int A[], int n, int target) {
        if (A[n-1] < target) return n;

        int low = 0, top = n - 1;
        while (low < top) {
            int mid = low + (top - low) / 2;
            if (A[mid] < target) {
                low = mid + 1;
            }
            else {
                top = mid;
            }
        }

        return low;
    }
};



#endif /* SEARCHINSERTPOSITION_H_ */
