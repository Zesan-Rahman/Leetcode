#include "common.h"
using namespace std;

class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> diffArray(nums.size() + 1, 0);
        diffArray[0] = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            diffArray[i] = nums[i] - nums[i-1];
        }
        for (int k = 0; k < queries.size(); k++) {
            int left = queries[k][0];
            int right = queries[k][1];
            diffArray[left] += -1;
            diffArray[right + 1] -= -1; 
        }
        for (int i = 0; i < nums.size(); i++) {
            if (i == 0) {
                nums[0] = diffArray[0];
            }
            else {
                nums[i] = nums[i-1] + diffArray[i];
            }
            if (nums[i] > 0) {
                return false;
            }
        }
        return true;
    }
};