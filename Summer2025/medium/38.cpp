#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        string result = "1";
        for (int i = 1; i < n; i++) {
            string prev = result;
            cout << "prev: " << prev << endl;
            result = "";//Reset result
            char currentChar = prev[0];
            int count = 0;
            for (int i = 0; i < prev.length(); i++) {
                if(prev[i] == currentChar) {
                    count++;
                }
                else {
                    result.push_back(count + '0');
                    result.push_back(currentChar);
                    currentChar = prev[i];
                    count = 1;
                }
            }
            result.push_back(count + '0');
            result.push_back(currentChar);
        }
        return result;
    }
};