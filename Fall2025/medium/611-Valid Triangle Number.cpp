#include <vector>
using namespace std;

class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        if(nums.size() < 3) return 0;
        sort(nums.begin(), nums.end());
        int res = 0;
        for(int i = 0; i < nums.size() - 2; i++) {
            if(nums[i] == 0) continue;
            for(int j = i + 1; j < nums.size() - 1; j++) {
                int upBound = nums[i] + nums[j];
                res += lower_bound(nums.begin() + j + 1, nums.end(), upBound) - (nums.begin() + j + 1);
            }
        }
        return res;
    }
};