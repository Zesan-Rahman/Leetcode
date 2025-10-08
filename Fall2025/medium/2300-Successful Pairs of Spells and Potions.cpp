#include <vector>
#include<algorithm>

class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int> pairs(spells.size());
        sort(potions.begin(), potions.end());
        for(size_t i = 0; i < spells.size(); i++) {
            int spellStrength = spells[i];
            if(success % spellStrength == 0) {
                pairs[i] = potions.end() - lower_bound(potions.begin(), potions.end(), success/spellStrength); 
            }
            else {
                pairs[i] = potions.end() - upper_bound(potions.begin(), potions.end(), success/spellStrength); 
            }
        }
        return pairs;
    }
};