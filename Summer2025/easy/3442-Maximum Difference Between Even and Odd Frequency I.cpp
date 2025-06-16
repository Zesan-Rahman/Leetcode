#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <math.h>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int maxDifference(string s) {
        unordered_map<char, int> hashTable;
        int oddFreq = 0; 
        float evenFreq = INFINITY; 
        for (size_t i = 0; i < s.length(); i++) {
            hashTable[s[i]]++;
        }
        for (auto i: hashTable) {
            if (i.second % 2 == 0 && i.second < evenFreq) {
                evenFreq = i.second;
            }
            if (i.second % 2 != 0 && i.second > oddFreq) {
                oddFreq = i.second;
            }
        }
        return oddFreq - evenFreq;
    }
};