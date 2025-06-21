#include <string>
#include <math.h>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int minimumDeletions(string word, int k) {
        unordered_map<char, int> table;
        for (char c: word) {
            table[c]++;
        }
        float minDeleted = INFINITY;
        for (auto i: table) {
            //Let i be the minimum frequent char
            int deleted = 0;
            int maxFreqAllowed = i.second + k;
            for(auto j: table) {
                //j cannot occur more than i.second + k, otherwise word isn't k special
                if(j.second > maxFreqAllowed) {
                    deleted += j.second - maxFreqAllowed;
                }
                //We want to make i the minimum frequent character, so we delete all of j's occurrences 
                if(j.second < i.second) {
                    deleted += j.second;
                }
            }
            if(minDeleted > deleted) {
                minDeleted = deleted;
            }
        }
        return minDeleted;
    }
};