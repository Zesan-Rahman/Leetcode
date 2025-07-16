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
    int maximumLength(vector<int>& nums) {
        int odds = 0;
        int evens = 0;
        int alternate = 0;
        bool lastElemEven = false;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] % 2 == 0) {
                evens++;
                if(!lastElemEven) {
                    alternate++;
                    lastElemEven = true;
                }
            }
            else {
                odds++;
                if(lastElemEven || alternate == 0) {
                    alternate++;
                    lastElemEven = false;
                }
            }
        }
        return max({odds, evens, alternate});
    }
};