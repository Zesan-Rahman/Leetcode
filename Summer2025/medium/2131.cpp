#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <math.h>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int length = 0;
        int doubles = 0;
        unordered_map<string, int> hashMap;
        for (size_t i = 0; i < words.size(); i++) {
            unordered_map<string, int>::iterator word = hashMap.find(words[i]);
            if (word == hashMap.end()) {//Word not in hashmap
                hashMap.insert({words[i], 1});
            }
            else {
                (word->second)++;
            }
        }
        bool middleDouble = false;
        for (auto& i: hashMap) {
            string word = i.first;
            int count = i.second;
            if(word[0] == word[1]) {//word is double, or 2 of the same letter
                if (count % 2 == 1) { //If odd, one goes to the middle unless there alr is a middle
                    cout << middleDouble << endl;
                    if(!middleDouble) length += 2;
                    count--;
                    middleDouble = true;
                }
                //This is for even but count will always be even at this point
                length += 2 * count;
                i.second = 0;
            }
            else {
                string reverseWord = word;
                reverseWord[0] = word[1];
                reverseWord[1] = word[0];
                unordered_map<string, int>::iterator revWord = hashMap.find(reverseWord);
                if(revWord != hashMap.end()) {//In hashmap
                    length += 2 * 2 * min(count, revWord->second);
                    revWord->second = 0;
                    i.second = 0;
                }   
            }
        }
        return length;
    }
};