#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool isValid(string word) {
        if(word.length() < 3) return false;
        vector<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        bool vowel = false;
        bool consonant = false;
        for(char c: word) {
            if(('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z')) {
                if(!vowel) {
                    vowel = find(vowels.begin(), vowels.end(), c) != vowels.end();
                }
                if(!consonant) {
                    consonant = find(vowels.begin(), vowels.end(), c) == vowels.end();
                }
            }
            else if(c < '0' || c > '9') return false;
        }
        return vowel && consonant; 
    }
};