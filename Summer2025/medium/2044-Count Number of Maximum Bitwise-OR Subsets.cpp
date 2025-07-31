#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <math.h>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution {
public:
	int countMaxOrSubsets(vector<int>& nums) {
		int max = 0;
		for(int i = 0; i < nums.size(); i++) {
			max = max | nums[i];
		}
		vector<vector<int>> subArrs;
		for(int i = 0; i < nums.size(); i++) {
			int subArrSize = subArrs.size(); //Subarray will grow in size in next loop
			for(int j = 0; j < subArrSize; j++) {
				subArrs.push_back(subArrs[j]);
				subArrs[subArrs.size()-1].push_back(nums[i]);
			}
			vector<int> temp = {nums[i]};
			subArrs.push_back(temp); 
		}
		int res = 0;
		for(int i = 0; i < subArrs.size(); i++) {
			int bitRes = 0;
			for(int j = 0; j < subArrs[i].size(); j++) {
				bitRes = (bitRes | subArrs[i][j]);
				if(bitRes == max) {
					res++;
					break;
				}
			}
		}
		return res;
	}
};

