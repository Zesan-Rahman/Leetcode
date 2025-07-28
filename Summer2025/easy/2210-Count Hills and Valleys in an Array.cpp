class Solution {
public:
    int countHillValley(vector<int>& nums) {
	    int res = 0;
	    for(int i = 1; i < nums.size()-1;) {
		int left = i-1;
		while(left >= 0 && nums[left] == nums[i]) {
			left--;
		}
		if(left < 0) left = 0;
		int right = i+1;
		while(right < nums.size() && nums[right] == nums[i]) {
			right++;
		}
		if(right == nums.size()) return res;
		if(nums[left] < nums[i] && nums[right] < nums[i]) {
			res++;
		}
		if(nums[left] > nums[i] && nums[right] > nums[i]) {
			res++;
		}
		i = right;
	    }
	    return res;
    }
};
