#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> freq;
        int maxFreq = 0;
        for(int i = 0; i < nums.size(); i++) {
            freq[nums[i]]++;
            maxFreq = max(maxFreq, freq[nums[i]]);
        }
        int res = 0;
        for(auto item: freq) {
            if(item.second == maxFreq) res += maxFreq;
        }
        return res;
    }
};