#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.length() == 0) return 0;
        int res = 0;
        int start = 0;
        unordered_map<char, int> index; //1-based indexing instead of 0-based since 0 = not an elem
        for(int i = 0; i < s.length(); i++) {
            if(i == s.length() - 1 && index[s[i]] == 0) {
                res = max(res, i - start + 1);
            }
            else if(index[s[i]] == 0) {
                index[s[i]] = i+1;
            }
            else { //Dupe char
                res = max(res, (i - 1) - start + 1);
                while(start < index[s[i]]) {
                    index[s[start]] = 0;
                    start++;
                }
                index[s[i]] = i + 1;
            }
        }
        return res;
    }
};
