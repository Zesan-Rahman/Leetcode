#include <vector>
#include <numeric>
#include <stack>

using namespace std;class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        stack<int> s;
        int sz = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(s.empty()) {
                s.push(nums[i]);
                sz++;
                continue;
            }
            int GCD = gcd(s.top(), nums[i]);
            if(GCD != 1) {
                int LCM = lcm(s.top(), nums[i]); 
                s.pop();
                while(!s.empty() && gcd(LCM, s.top()) != 1) {
                    LCM = lcm(LCM, s.top());
                    s.pop();
                    sz--;
                }
                s.push(LCM);
            }
            else {
                s.push(nums[i]);
                sz++;
            }
        }
        vector<int> res(sz);
        while(!s.empty()) {
            res[sz - 1] = s.top();
            s.pop();
            sz--;
        }
        return res;
    }
};