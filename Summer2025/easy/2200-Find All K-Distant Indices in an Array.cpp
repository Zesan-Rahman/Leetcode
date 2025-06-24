#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int> result;
        int greatestIndex = -1;
        for (int i = 0; i < nums.size(); i++) {
            if(nums[i] == key) {
                //Set starting point at i-k or 0
                int counter = i-k;
                if(counter < 0) counter = 0;
                //Run through subsection of the array
                while (counter < nums.size() && counter <= i+k) {
                    if(counter > greatestIndex) {
                        result.push_back(counter);
                        greatestIndex = counter;
                        //We can reencounter a key only after i. 
                        //To avoid skipping this key, we set i to now be this new index.
                        if(nums[counter] == key) {
                            i = counter;
                        }
                    }
                    counter++;
                }
                i += k;
            }
        }
        return result;
   }
};