#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <queue>
using namespace std;

#define alphabetSize 26

class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        //Using an inner boolean vector so I can avoid inserting repeats later
        vector<vector<bool>> alphabetBool(alphabetSize);
        vector<char> alphabet(alphabetSize);
        for (size_t i = 0; i < alphabetSize; i++) {
            alphabetBool[i] = vector<bool>(26, false);
        }
        for (size_t i = 0; i < s1.length(); i++) {
            char c1 = s1[i] - 'a';
            char c2 = s2[i] - 'a';
            //Mark the letters equal to each other
            //Note: If I used a char inner vector, I would have to check the vector to ensure no repeats
            alphabetBool[c1][c2] = true;
            alphabetBool[c2][c1] = true;
        }
        //-1 means never visited, 0 means visited in this current tree, 1 means visited and reduced already
        vector<int> visited(alphabetSize, -1);
        //Reduce each letter in the alphabet
        for (size_t i = 0; i < alphabetSize; i++) {
            if(visited[i] == -1) {
                BFSreduce(alphabetBool, visited, i, alphabet);
            }
        }
        //
        for (size_t i = 0; i < baseStr.length(); i++) {
            baseStr[i] = alphabet[baseStr[i] - 'a'];
        }
        return baseStr;
    }

    void BFSreduce(vector<vector<bool>>& alphabetBool, vector<int>& visited, int root, vector<char>& alphabet) {
        char minChar = root + 'a';
        queue<int> q;
        q.push(root);
        while(!q.empty()) {
            int currentIndex = q.front();
            q.pop();
            visited[currentIndex] = 0;
            if (minChar > currentIndex + 'a') {
                minChar = currentIndex + 'a';
            }
            for (size_t i = 0; i < alphabetBool[currentIndex].size(); i++) {
                //Check if letter is equal and not visited
                if(alphabetBool[currentIndex][i] && visited[i] == -1) {
                    q.push(i);
                }
            }
        }
        //Run through the letters we have visited and set their chars to minchar
        for (size_t i = 0; i < visited.size(); i++) {
            if (visited[i] == 0) {
                alphabet[i] = minChar;
                visited[i] = 1;
            }
        }
    }
};