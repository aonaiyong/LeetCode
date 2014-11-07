/*
 Author:     naiyong, aonaiyong@gmail.com
 Date:       Sep 22, 2014
 Problem:    Two Sum
 Difficulty: 2
 Source:     https://oj.leetcode.com/problems/two-sum/
 Notes:
 Given an array of integers, find two numbers such that they add up to a specific target number.

 The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.

 You may assume that each input would have exactly one solution.

 Input: numbers={2, 7, 11, 15}, target=9
 Output: index1=1, index2=2

 Solution:   1. Sort and Squeeze.
                Given a sorted array A[n], find i and j so that A[i] + A[j] == target.

                A    |             <              |
                      low                     high
                A[low] + A[high] ? target
                I.   ==,  return.
                II.  <,   ++low.
                    Since A[low] + A[j] <= A[low] + A[high] < target, A[low] is ruled out.
                III. >,   --high.
                    Since A[i] + A[high] >= A[low] + A[high] > target, A[high] is ruled out.

                Time: O(nlogn), Space: O(1).

             2. Hash (one pass).
                Time: O(n), Space: O(n).

             3. Hash (two passes).
                Time: O(n), Space: O(n).
 */

#ifndef TWOSUM_H_
#define TWOSUM_H_

#include <vector>
using std::vector;

#include <unordered_map>
using std::unordered_map;

#include <algorithm>
using std::sort;
using std::min; using std::max;

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        return twoSumHash2P(numbers, target);
    }

    // O(nlog(n)) time, O(n) space
    vector<int> twoSumSort(vector<int> &num, int target) {
        int n = num.size();
        vector<int> ind(n);
        for (int i = 0; i < n; ++i)
            ind[i] = i;
        sort(ind.begin(), ind.end(),
             [&num](int i, int j) { return num[i] < num[j]; });

        int low = 0, high = n - 1;
        while (low < high) {
            int i = ind[low], j = ind[high];
            int sum = num[i] + num[j];
            if (sum == target)
                return {min(i, j) + 1, max(i, j) + 1};
            else if (sum < target)  // exclude num[i]
                ++low;
            else            // exclude num[j]
                --high;
        }
        return {-1, -1};
    }

    // O(n) time, O(n) space
    vector<int> twoSumHash1P(const vector<int> &num, int target) {
        int n = num.size();
        unordered_map<int, int> umap;
        for (int i = 0; i < n; ++i) {
            int diff = target - num[i];
            if (umap.count(diff))
                return {umap[diff] + 1, i + 1};
            umap[num[i]] = i;   // at this point, it's safe to overwrite
        }
        return {-1, -1};
    }

    // O(n) time, O(n) space
    vector<int> twoSumHash2P(const vector<int> &num, int target) {
         int n = num.size();
         unordered_map<int, vector<int> > umap;
         for (int i = 0; i < n; ++i)
             umap[num[i]].push_back(i);

         for (int i = 0; i < n; ++i) {
             int diff = target - num[i];
             if (umap.count(diff)) {
                 int j = umap[diff][0];
                 if (diff == num[i]) {
                     if (umap[diff].size() == 1)
                         continue;
                     j = umap[diff][1];  // ensure different indices
                 }
                 return {min(i, j) + 1, max(i, j) + 1};
             }
         }
         return {-1, -1};
     }
};

#endif /* TWOSUM_H_ */
