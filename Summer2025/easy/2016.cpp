#include <vector>
using namespace std;

class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int smallest = nums[0];
        int maxDiff = 0;
        for (size_t i = 1; i < nums.size(); i++) {
            if(nums[i] - smallest > maxDiff) {
                maxDiff = nums[i] - smallest;
            }
            if(nums[i] < smallest) {
                smallest = nums[i];
            }
        }
        if (maxDiff == 0) {
            return -1;
        }
        else {
            return maxDiff;
        }
    }
};