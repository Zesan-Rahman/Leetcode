#include <string>
#include <math.h>
using namespace std;

class Solution {
public:
    int longestSubsequence(string s, int k) {
        int result = 0;
        bool canInsert1 = true;
        int num = 0;
        int binaryLength = floor(log2(k)) + 1;
        for(int i = s.size()-1; i >= 0; i--) {
            if(result > binaryLength) {
                canInsert1 = false;
            }
            if(s[i] == '1' && canInsert1) {
                num += 1 << result;
                if(num > k) {

                    
                    canInsert1 = false;
                }
                else {
                    result++;
                }
            }
            if(s[i] == '0') {
                result++;
            }
        }
        return result;
    }
};