#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> result = {""};
        for(char c: s) {
            if(result[result.size()-1].length() == k) {
                result.push_back("");
            }
            result[result.size()-1].push_back(c);
        }
        while(result[result.size()-1].length() < k) {
            result[result.size()-1].push_back(fill);
        }   
        return result;
    }
};