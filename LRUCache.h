/*
 Author:      naiyong, aonaiyong@gmail.com
 Date:        Nov 24, 2014
 Problem:     LRU Cache
 Difficulty:  4
 Source:      https://oj.leetcode.com/problems/lru-cache/
 Notes:
 Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and set.

  get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
  set(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate
  the least recently used item before inserting a new item.

 Solution:    List + Hash.
 */

#ifndef LRUCACHE_H_
#define LRUCACHE_H_

#include <list>
using std::list;

#include <unordered_map>
using std::unordered_map;

struct CacheNode {
    int key;
    int value;
    CacheNode(int k, int v) : key(k), value(v) {}
};

class LRUCache{
public:
    LRUCache(int capacity) : size(capacity) {}

    int get(int key) {
        if (cacheMap.count(key)) { // if the key exists
            cacheList.splice(cacheList.begin(), cacheList, cacheMap[key]); // move the node to the head
            return cacheMap[key]->value;
        }
        else
            return -1;
    }

    void set(int key, int value) {
        if (cacheMap.count(key)) { // if the key exists
            cacheList.splice(cacheList.begin(), cacheList, cacheMap[key]); // move the node to the head
            cacheMap[key]->value = value; // update the value
        }
        else { // if the key is not present
            if (cacheList.size() == size) { // if the cache reached its capacity
                cacheMap.erase(cacheList.back().key);
                cacheList.pop_back();
            }
            cacheList.push_front(CacheNode(key, value));
            cacheMap[key] = cacheList.begin();
        }
    }

private:
    list<CacheNode> cacheList; // key - value
    unordered_map<int, list<CacheNode>::iterator> cacheMap;  // key -> address
    int size;
};

#endif /* LRUCACHE_H_ */
