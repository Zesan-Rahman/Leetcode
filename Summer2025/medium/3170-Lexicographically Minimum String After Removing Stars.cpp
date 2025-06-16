#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

class Solution {
public:
    struct comp {
        bool operator() (const pair<char, size_t>& a, const pair<char, size_t>& b) {
            //Smaller char will have higher prio
            if(a.first != b.first) {
                return a.first > b.first; 
            }
            //Greater index will have higher prio if chars =
            return a.second < b.second;
        }
    };

    string clearStars(string s) {
        priority_queue<pair<char, size_t>, vector<pair<char, size_t>>, comp> q;
        for(size_t i = 0; i < s.length(); i++) {
            if(s[i] != '*') {
                q.push(pair(s[i], i));
            }
            else {
                auto current = q.top();
                q.pop();
                s[current.second] = '-';
                s[i] = '-';
            }
        }
        string result;
        for (size_t i = 0; i < s.length(); i++) {
            if(s[i] != '-') {
                result.push_back(s[i]);
            }
        }
        return result;
    }
};