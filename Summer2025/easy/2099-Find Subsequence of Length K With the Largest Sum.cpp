#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> maxSubsequence(vector<int> nums, int k) {
        vector<int> result = nums;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size() - k; i++) {
            int target = nums[i];
            result.erase(find(result.begin(), result.end(), target));
        }
        return result;
    }
};