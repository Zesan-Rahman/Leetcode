#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <math.h>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> hashTable;
        for (int i = 0; i < nums.size(); i++) {
            hashTable[nums[i]]++;
        }
        vector<int> result;
        int leastFrequentIndex = 0;
        int leastFrequentCount = 0;
        for (pair<int, int> i: hashTable) {
            //Add elements until we have k results
            if (result.size() < k) {
                result.push_back(i.first);
                int leastFrequent = result[leastFrequent];
                if(hashTable[leastFrequent] > i.second) {
                    leastFrequentCount = i.second;
                    leastFrequentIndex = result.size() - 1;
                }
            }
            //Replace an element if we have k results
            else if(leastFrequentCount < i.second) {
                result[leastFrequentIndex] = i.first;
                //Need to reset leastFrequent info
                //First find new leastFrequentIndex
                for (int j = 0; j < result.size(); j++) {
                    int leastFrequent = result[leastFrequentIndex];
                    int current = result[j];
                    if(hashTable[leastFrequent] > hashTable[current]) {
                        leastFrequentIndex = j;
                    }
                }
                //Second, get the new leastFrequentCount
                leastFrequentCount = hashTable[result[leastFrequentIndex]];
            }
        }
        return result;
    }
};