#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class FindSumPairs {
public:
    FindSumPairs(vector<int>& nums1in, vector<int>& nums2in) {
        nums1 = nums1in;
        nums2 = nums2in;
        for(int i = 0; i < nums1.size(); i++) {
            counts1[nums1[i]]++;
        }
        for(int i = 0; i < nums2.size(); i++) {
            counts2[nums2[i]]++;
        }
    }
    
    void add(int index, int val) {
        counts2[nums2[index]]--;
        nums2[index] += val;
        counts2[nums2[index]]++;
        
    }
    
    int count(int tot) {
        int result = 0; 
        for(auto i: counts1) {
            if(counts2.find(tot-i.first) != counts2.end()) {
                result += i.second * counts2[tot - i.first];
            }
        }
        return result;
    }
private:
    vector<int> nums1;
    vector<int> nums2;
    unordered_map<int, int> counts1;
    unordered_map<int, int> counts2;
};
