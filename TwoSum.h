/*
 Author:     naiyong, aonaiyong@gmail.com
 Date:       Sep 22, 2014
 Problem:    TwoSum.h
 Difficulty:
 Source:
 Notes:

 Solution:
 */

#ifndef TWOSUM_H_
#define TWOSUM_H_

#include <vector>
using std::vector;

#include <unordered_map>
using std::unordered_map;

#include <algorithm>
using std::min; using std::max;

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        return twoSumHashOnePass(numbers, target);
    }

    // O(nlog(n)) time, O(n) space
    vector<int> twoSumSort(vector<int> &num, int target) {
        int n = num.size();
        vector<int> ind(n);
        for (int i = 0; i < n; ++i) {
            ind[i] = i;
        }
        sort(ind.begin(), ind.end(),
             [&num](int i, int j) { return num[i] < num[j]; });

        int low = 0, top = n - 1;
        while (low < top) {
            int i = ind[low], j = ind[top];
            int sum = num[i] + num[j];
            if (sum == target) {
                return {min(i, j) + 1, max(i, j) + 1};
            }

            if (sum < target) { // skip nums[i]
                ++low;
            }
            else {              // skip nums[j]
                --top;
            }
        }

        return {-1, -1};
    }

    // O(n) time, O(n) space
    vector<int> twoSumHashTwoPass(vector<int> &num, int target) {
        int n = num.size();
        unordered_map<int, vector<int>> umap;
        for (int i = 0; i < n; ++i) {
            umap[num[i]].push_back(i);
        }

        for (int i = 0; i < n; ++i) {
            auto it = umap.find(target - num[i]);
            if (it != umap.end()) {
                int j = it->second[0];
                if (num[i] == target - num[i]) {
                    if (it->second.size() == 1) {
                        continue;
                    }
                    j = it->second[1];  // ensure different indices
                }

                return {min(i, j) + 1, max(i, j) + 1};
            }
        }

        return {-1, -1};
    }

    // O(n) time, O(n) space
    vector<int> twoSumHashOnePass(vector<int> &num, int target) {
        int n = num.size();
        unordered_map<int, int> mp;
        for (int i = 0; i < n; ++i) {
            auto it = mp.find(target - num[i]);
            if (it != mp.end()) {
                return {min(i, it->second) + 1, max(i, it->second) + 1};
            }

            mp[num[i]] = i;  // at this point, it's safe to overwrite
        }

        return {-1, -1};
    }
};

#endif /* TWOSUM_H_ */
