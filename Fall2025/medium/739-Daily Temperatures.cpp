#include<vector>
#include<stack>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(const vector<int>& temperatures) const {
        vector<int> res(temperatures.size(), 0);
        stack<pair<int, int>> stk;
        stk.push({temperatures[0], 0});
        for(size_t i = 1; i < temperatures.size(); i++) {
            while(!stk.empty() && stk.top().first < temperatures[i]) {
                pair<int, int> temp = stk.top();
                stk.pop();
                res[temp.second] = i - temp.second;     
            }
            stk.push({temperatures[i], i});   
        }
        return res;
    }
};