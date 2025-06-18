#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        vector<int> numbers = nums;
        sort(numbers.begin(), numbers.end());
        vector<vector<int>> results;
        for(size_t i = 0; i < numbers.size(); i += 3) {
            if(numbers[i+1] - numbers[i] > k || numbers[i+2] - numbers[i+1] > k || numbers[i+2] - numbers[i] > k) {
                return vector<vector<int>>();
            }
            results.push_back({numbers[i], numbers[i+1], numbers[i+2]});
        }
        return results;
    }
};