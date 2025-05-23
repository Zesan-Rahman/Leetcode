#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
#include <math.h>
using namespace std;

class Solution {
public:
    int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
        auto comp = [](const vector<int> l, const vector<int> r) {
            return l[0] < r[0];
        };
        sort(queries.begin(), queries.end(), comp);
        
        priority_queue<int> prioQueue;
        vector<int> diffArray(nums.size() + 1, 0);
        diffArray[0] = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            diffArray[i] = nums[i] - nums[i-1];
        }
        //k is an index tracker in queries
        for (int i = 0, k = 0; i < nums.size(); i++) {
            int neededQueries = nums[0]; 
            int operations = 0;
            if (i > 0) {
                neededQueries = nums[i-1] + diffArray[i];
            }
            int oldSize = prioQueue.size();
            //Obtain all valid queries
            while (k < queries.size() && i == queries[k][0]) {
                prioQueue.push(queries[k][1]);
                k++;
            }
            //Only checking the elements corresponding to i
            while(operations <= neededQueries && prioQueue.size() > oldSize && prioQueue.top() >= i) {
                operations++;
                diffArray[prioQueue.top() + 1] -= 1;
                prioQueue.pop();
            }
            if (operations <= neededQueries) {
                return -1;
            }
        }
        return prioQueue.size();
    }
};