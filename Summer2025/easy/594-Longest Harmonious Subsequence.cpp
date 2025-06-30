#include <vector>
#include <algorithm>
#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> table;
        for(int i = 0; i < nums.size(); i++) {
            table[nums[i]]++;
        }
        int maxLength = 0;
        for(auto i: table) {
            int lesser = 0;
            int greater = 0;
            if(table.find(i.first + 1) != table.end()) {
                greater = i.second + table[i.first + 1];
            }
            if(table.find(i.first - 1) != table.end()) {
                lesser = i.second + table[i.first - 1];
            }
            maxLength = max(maxLength, max(lesser, greater));
        }
        return maxLength;
    }
};