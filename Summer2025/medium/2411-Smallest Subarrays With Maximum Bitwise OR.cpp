#include <bitset>
#include <vector>
using namespace std;

class Solution {
public:
	vector<int> smallestSubarrays(vector<int>& nums) {
		bitset<32> max(0);
		vector<int> bitGivers(32, -1);
		vector<int> ans(nums.size());
		for(int i = nums.size()-1; i >= 0; i--) {
			bitset<32> num(nums[i]);
			for(int j = 0; j < max.size(); j++) {
				if(max[j] == 0 && num[j] == 1) {
					bitGivers[j] = i;  
				}
				if(max[j] == 1 && num[j] == 1) {
					bitGivers[j] = min(bitGivers[j], i);
				}
				
			}
			int lastGiver = -1;
			for(int j = 0; j < bitGivers.size(); j++) {
				if(bitGivers[j] > lastGiver) {
					lastGiver = bitGivers[j];
				}
			}
			if(lastGiver == -1) {
				lastGiver = i;
			}
			ans[i] = lastGiver - i + 1;
		}
		return ans;
    }
};
