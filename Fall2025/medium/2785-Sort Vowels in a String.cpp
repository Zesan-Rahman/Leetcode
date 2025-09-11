#include <vector>
#include <string>
#include <queue>
using namespace std;

class Solution {
public:
    string sortVowels(string s) {
        string vowels = "aeiouAEIOU";
        auto comp = [](char a, char b) {
            return a > b;
        };
        priority_queue<char, vector<char>, decltype(comp)> prioQueue(comp);
        for(char c: s) {
            if(vowels.find(c) != string::npos) {
                prioQueue.push(c);
            }
        }
        for(size_t i = 0; i < s.length(); i++) {
            if(vowels.find(s[i]) != string::npos) {
                s[i] = prioQueue.top();
                prioQueue.pop();
            }
        }
        return s;
    }
};
