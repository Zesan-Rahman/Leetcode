#include <vector>
#include <iostream>
#include <math.h>
using namespace std;

class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int maxDiff = abs(nums[nums.size() - 1] - nums[0]);
        for (int i = 1; i < nums.size(); i++) {
            if(maxDiff < abs(nums[i] - nums[i-1])) {
                maxDiff = abs(nums[i] - nums[i-1]);
            }
        }
        return maxDiff;
    }
};